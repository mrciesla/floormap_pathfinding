

void initialize_options(Game &game)
{
	game.options.queue = false;
  game.options.stack = false;

  game.options.output_map = false;
  game.options.output_list = false;
  game.options.input_map = false;
}

void get_options(Game &game, int argc, char *argv[])
{
	string alg_opt;

  static struct option long_options[] =
  {     
    { "output",  required_argument, 0, 'o' },    
    {  "stack",        no_argument, 0, 's' }, 
    {  "queue",        no_argument, 0, 'q' }, 
    {   "help",        no_argument, 0, 'h' }, 
    {        0,                  0, 0,  0  }
  }; 
   
  while (true) // parse all the options
  {
    int option_index = 0;
    int c = getopt_long(argc, argv, "sqo:h", long_options, &option_index);

    if (c == -1) break; //End of options
    switch (c) 
    {
      case 0:
        break;
        
      case 's':
        game.options.stack = true;
        break;
        
      case 'q':
        game.options.queue = true;
        break;
        
      case 'o':
        alg_opt = optarg;
        if(alg_opt == "M") game.options.output_map = true;
        else if (alg_opt == "L") game.options.output_list = true;
        else error("Incorrect output parameter. Must be (M|L).", 0);
        break;
        
      case 'h':
        print_help(); 
        exit(0);
        
      default:
        abort ();
    }
  } 
}

void check_options(Game &game)
{
  if (game.options.stack && game.options.queue) 
  	error("Incorrect arguments. Cannot declare stack and queue.", 1);
  else if ((!game.options.stack) && (!game.options.queue)) 
  	error("Incorrect arguments. Must declare stack or queue.", 1);

  if((!game.options.output_list) && (!game.options.output_map)) 
  	game.options.output_map = true;
}

void set_options(Game &game, int argc, char *argv[])
{
	initialize_options(game);
	get_options(game, argc, argv);
	check_options(game);
}
