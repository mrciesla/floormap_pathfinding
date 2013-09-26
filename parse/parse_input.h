void parse_input(Game &game)
{  
	if (game.options.input_map) 
    read_map_file(game);
  else 
    read_list_file(game);
}