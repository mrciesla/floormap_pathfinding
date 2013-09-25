void print_list(Stack<Coordinate> &path_taken, int &path_length,
               Coordinate &c)
{
	cout << "//path taken" << endl;
	while (path_length)
	{  
		if (!path_taken.isEmpty())
		{  
			c = path_taken.pop();
		  cout << "(" << c.y << "," << c.x << "," << c.f << ","
		       << floor_type[c.t] << ")" << endl;
		  path_length--;
		}
	}
}


void print_map(SpaceShip &ss, Options &options, Path ***ship_map,
                 Stack<Coordinate> &path_taken, int &path_length,
                 Coordinate &c)
{
	for(int f = (ss.num_floors - 1); f >= 0; f--)
  {
  	cout << "//room " << f << endl;
    for(int y = 0; y < ss.size_floors; y++)
    {  
    	for(int x = 0; x < ss.size_floors; x++)
        cout << floor_type[ship_map[f][x][y].t];
      cout << endl;
    }
  }
}