bool can_move_to_coord(Coordinate neighbor, Path ***ship_map)
{  if (ship_map[neighbor.f][neighbor.x][neighbor.y].visited) return false;
   if (neighbor.t == WALL) return false;
   if (neighbor.t == OK) return true;
   if (neighbor.t == ELEVATOR) return true;
   else return false;
}

void find_hangar(SpaceShip &ss, Options &options, Path ***ship_map,
                 Stack<Coordinate> stack_list, Queue<Coordinate> queue_list,
                 bool &found_hangar)
{
  if(options.queue) queue_list.enqueue(ss.start);
  else stack_list.push(ss.start);
   
  int list_size = 1;

  while((!found_hangar) && list_size)
  { 
    if(options.queue) ss.cur = queue_list.dequeue();
    else ss.cur = stack_list.pop();
    list_size--;
    print_coord(ss.cur);

    Coordinate neighbor;
    //cout << "cardinal directions" << endl;
    //cout << "ss.cur type is " << ss.cur.t << endl;
    for(int i = 0; i < 4; i++)
    { //cout << "ss.cur type is " << ss.cur.t << "  inside foor loop" << endl;
      neighbor = ss.cur;
      neighbor.x = ss.cur.x + COMPASS[i][0];
      neighbor.y = ss.cur.y + COMPASS[i][1];
      
      if(is_in_spaceship(neighbor, ss))
      { 
        // Signal 11, or officially know as "segmentation fault", means that 
        // the program accessed a memory location that was not assigned
        neighbor.t = ship_map[neighbor.f][neighbor.x][neighbor.y].t;

        if (neighbor.t == HANGAR)
        {  
          found_hangar = true; 
          ss.hangar_adj = ss.cur; 
          ship_map[ss.hangar.f][ss.hangar.x][ss.hangar.y].from_direction = COMPASS[i][2];
          ship_map[ss.hangar.f][ss.hangar.x][ss.hangar.y].from_coord = ss.cur;
        }
        else if (can_move_to_coord(neighbor, ship_map))
        {  cout << "                                   ";
           print_coord(neighbor, "can move to this");
          if(options.queue) queue_list.enqueue(neighbor);
          else stack_list.push(neighbor);
          list_size++;
          ship_map[neighbor.f][neighbor.x][neighbor.y].visited = true;
          ship_map[neighbor.f][neighbor.x][neighbor.y].from_direction = COMPASS[i][2];
          ship_map[neighbor.f][neighbor.x][neighbor.y].from_coord = ss.cur;
        }
      }
    }  

    if (ss.cur.t == ELEVATOR) //If on a elevator, neighbors are other floors
    { cout << "elevator" << endl;
      neighbor = ss.cur; 

      // for (int floor_num = (ss.num_floors - 1); floor_num >= 0; floor_num--)
      for (int floor_num = 0; floor_num < ss.num_floors; floor_num++)
      { cout << "checking floor: " << floor_num << endl;
        neighbor.f = floor_num;
        neighbor.t = ship_map[neighbor.f][neighbor.x][neighbor.y].t;
        if (neighbor.t == ELEVATOR)//&& can_move_to_coord(neighbor, ship_map) 
        { cout << "there's an E on floor: " << floor_num << endl;
          if(ship_map[neighbor.f][neighbor.x][neighbor.y].visited)
          { cout << "that E is UNvisited: " << floor_num << endl;
            if(options.queue) queue_list.enqueue(neighbor);
            else stack_list.push(neighbor);
            list_size++;
            ship_map[neighbor.f][neighbor.x][neighbor.y].visited = true;
            ship_map[neighbor.f][neighbor.x][neighbor.y].from_direction = ss.cur.f;
            ship_map[neighbor.f][neighbor.x][neighbor.y].from_coord = ss.cur;
          }
        }
      }
    }
  } //End of while((!found_hangar) && list_size)
}
