
void retrace_path(SpaceShip &ss, Options &options, Path ***ship_map,
                  Stack<Coordinate> &path_taken, int &path_length,
                  Coordinate &coord)
{

  ss.cur = ss.hangar_adj;
  ss.prev = ss.hangar;

  while (ss.cur.t != START)
  {  
    ship_map[ss.cur.f][ss.cur.x][ss.cur.y].t
    =  ship_map[ss.prev.f][ss.prev.x][ss.prev.y].from_direction;
     
    if(!options.output_map)
    {
      coord.f = ss.cur.f;
      coord.x = ss.cur.x;
      coord.y = ss.cur.y;
      coord.t = ship_map[ss.cur.f][ss.cur.x][ss.cur.y].t;
      path_taken.push(coord);
    }

    ss.cur = ship_map[ss.cur.f][ss.cur.x][ss.cur.y].from_coord;
    ss.prev = ship_map[ss.prev.f][ss.prev.x][ss.prev.y].from_coord;

    path_length++;
  } 

  ship_map[ss.cur.f][ss.cur.x][ss.cur.y].t
  =  ship_map[ss.prev.f][ss.prev.x][ss.prev.y].from_direction;

  if(!options.output_map)
  {
    coord.f = ss.cur.f;
    coord.x = ss.cur.x;
    coord.y = ss.cur.y;
    coord.t = ship_map[ss.cur.f][ss.cur.x][ss.cur.y].t;
    path_taken.push(coord);
  }

}