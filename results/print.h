void print_list(Game &game)
{
	cout << "//path taken" << endl;
	while (game.path_length)
	{  
		if (!game.path_taken.empty())
		{  
			game.path_coord = game.path_taken.top();
			game.path_taken.pop();
		  cout << "(" << game.path_coord.y << "," 
		  	          << game.path_coord.x << "," 
		  	          << game.path_coord.f << ","
		              << floor_type[game.path_coord.t] 
		              << ")" << endl;
		  game.path_length--;
		}
	}
}


void print_map(Game &game)
{
	for(int f = (game.num_floors - 1); f >= 0; f--)
  {
  	cout << "//room " << f << endl;
    for(int y = 0; y < game.size_floors; y++)
    {  
    	for(int x = 0; x < game.size_floors; x++)
        cout << floor_type[game.map[f][x][y].t];
      cout << endl;
    }
  }
}

void print_results(Game &game)
{

	cout << game.size_floors << "\n" << game.num_floors << endl;
  if(!game.options.output_map)
    print_list(game);
  else
    print_map(game);
}