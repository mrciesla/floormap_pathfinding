
void retrace_path(Game &game)
{
  if(!game.found_hangar) return;
  game.cur = game.hangar_adj;
  game.prev = game.hangar;

  while (game.cur.t != START)
  {  
    game.map[game.cur.f][game.cur.x][game.cur.y].t
    =  game.map[game.prev.f][game.prev.x][game.prev.y].from_direction;
     
    if(!game.options.output_map)
    {
      game.path_coord.f = game.cur.f;
      game.path_coord.x = game.cur.x;
      game.path_coord.y = game.cur.y;
      game.path_coord.t = game.map[game.cur.f][game.cur.x][game.cur.y].t;
      game.path_taken.push(game.path_coord);
    }

    game.cur = game.map[game.cur.f][game.cur.x][game.cur.y].from_coord;
    game.prev = game.map[game.prev.f][game.prev.x][game.prev.y].from_coord;

    game.path_length++;
  } 

  game.map[game.cur.f][game.cur.x][game.cur.y].t
  =  game.map[game.prev.f][game.prev.x][game.prev.y].from_direction;

  if(!game.options.output_map)
  {
    game.path_coord.f = game.cur.f;
    game.path_coord.x = game.cur.x;
    game.path_coord.y = game.cur.y;
    game.path_coord.t = game.map[game.cur.f][game.cur.x][game.cur.y].t;
    game.path_taken.push(game.path_coord);
  }

}