void init(Game &game, int argc, char *argv[])
{ 
	set_options(game, argc, argv);
  read_header_info(game);
  allocate_memory(game);
  game.found_hangar = false;
  game.path_length = 1;
}