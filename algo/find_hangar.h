bool can_move_to_coord(Game &game, Coordinate neighbor)
{  if (game.map[neighbor.f][neighbor.x][neighbor.y].visited) return false;
   if (neighbor.t == WALL) return false;
   if (neighbor.t == OK) return true;
   if (neighbor.t == ELEVATOR) return true;
   else return false;
}

void set_current_coordinate(Game &game)
{
  if(game.options.queue) 
  { 
    game.cur = game.queue_list.front();
    game.queue_list.pop();
  }
  else
  { 
    game.cur = game.stack_list.top();
    game.stack_list.pop();
  }
}

int coordinate_type(Game &game, Coordinate &coord)
{
  return game.map[coord.f][coord.x][coord.y].t;
}

void find_hangar(Game &game)
{
  if(game.options.queue) game.queue_list.push(game.start);
  else game.stack_list.push(game.start);
   
  int list_size = 1;

  while((!game.found_hangar) && list_size)
  { 
    set_current_coordinate(game);
    list_size--;

    Coordinate neighbor;

    for(int i = 0; i < 4; i++)
    { 
      neighbor = game.cur;
      neighbor.x = game.cur.x + COMPASS[i][0];
      neighbor.y = game.cur.y + COMPASS[i][1];
      
      if(is_in_spaceship(game, neighbor))
      { 
        neighbor.t = coordinate_type(game, neighbor);

        if (neighbor.t == HANGAR)
        {  
          game.found_hangar = true; 
          game.hangar_adj = game.cur; 
          game.map[game.hangar.f][game.hangar.x][game.hangar.y].from_direction = COMPASS[i][2];
          game.map[game.hangar.f][game.hangar.x][game.hangar.y].from_coord = game.cur;
        }
        else if (can_move_to_coord(game, neighbor))
        {  
          if(game.options.queue) game.queue_list.push(neighbor);
          else game.stack_list.push(neighbor);
          list_size++;
          game.map[neighbor.f][neighbor.x][neighbor.y].visited = true;
          game.map[neighbor.f][neighbor.x][neighbor.y].from_direction = COMPASS[i][2];
          game.map[neighbor.f][neighbor.x][neighbor.y].from_coord = game.cur;
        }
      }
    }  

    if (game.cur.t == ELEVATOR) 
    { 
      neighbor = game.cur; 

      for (int floor_num = 0; floor_num < game.num_floors; floor_num++)
      { 
        neighbor.f = floor_num;
        neighbor.t = coordinate_type(game, neighbor);
        if (neighbor.t == ELEVATOR)
        { 
          if(!game.map[neighbor.f][neighbor.x][neighbor.y].visited)
          { 
            if(game.options.queue) game.queue_list.push(neighbor);
            else game.stack_list.push(neighbor);
            list_size++;
            game.map[neighbor.f][neighbor.x][neighbor.y].visited = true;
            game.map[neighbor.f][neighbor.x][neighbor.y].from_direction = neighbor.f; //game.cur.f
            game.map[neighbor.f][neighbor.x][neighbor.y].from_coord = game.cur;
          }
        }
      }
    }
  } 
}
