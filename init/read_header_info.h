void read_map_or_list(Game &game, string line_input)
{
  string letterM("M");
  string letterL("L");

  if (line_input.length() > 1) error("Incorrect input file format.", 1);

  if (line_input[0] == letterM[0]) game.options.input_map = true;
  else if (line_input[0] == letterL[0]) game.options.input_map = false;
  else error("Incorrect input format.", 1);
}

void read_size_floors(Game &game, string line_input)
{ 
	game.size_floors = atoi(line_input.c_str());
  if (game.size_floors < 2) 
    error("Floor size input must be at least 2x2.", 1);
}

void read_num_floors(Game &game, string line_input)
{ 
	game.num_floors = atoi(line_input.c_str());
  if ((game.num_floors < 1)) error("Number of floors must be 1-10", 1);
}


void read_header_info(Game &game)
{
  string line_input;

  getline(cin, line_input);
  read_map_or_list(game, line_input);

  getline(cin, line_input);
  read_size_floors(game, line_input);
  
  getline(cin, line_input);
  read_num_floors(game, line_input);
}

void allocate_memory(Game &game)
{  
  game.map = new FloorTile**[game.num_floors];
  for (int i = 0; i < game.num_floors; ++i)
  {  
    game.map[i] = new FloorTile*[game.size_floors];

    for (int j = 0; j < game.size_floors; ++j)
      game.map[i][j] = new FloorTile[game.size_floors];     
  }
}