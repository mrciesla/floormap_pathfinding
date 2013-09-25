
void read_map_or_list(SpaceShip &ss, Options &options, string line_input)
{
  string letterM("M");
  string letterL("L");

  if (line_input.length() > 1) error("Incorrect input file format.", 1);

  if (line_input[0] == letterM[0]) options.input_map = true;
  else if (line_input[0] == letterL[0]) options.input_map = false;
  else error("Incorrect input format.", 1);
}

void read_size_floors(SpaceShip &ss, string line_input)
{ 
	ss.size_floors = atoi(line_input.c_str());
  if (ss.size_floors < 2) 
    error("Floor size input must be at least 2x2.", 1);
}

void read_num_floors(SpaceShip &ss, string line_input)
{ 
	ss.num_floors = atoi(line_input.c_str());
  if ((ss.num_floors < 1)) error("Number of floors must be 1-10", 1);
}


void read_header_info(SpaceShip &ss, Options &options)
{
  string line_input;

  getline(cin, line_input);
  read_map_or_list(ss, options, line_input);

  getline(cin, line_input);
  read_size_floors(ss, line_input);
  
  getline(cin, line_input);
  read_num_floors(ss, line_input);
}

void allocate_memory(Path &ship_map, SpaceShip ss)
{  
}