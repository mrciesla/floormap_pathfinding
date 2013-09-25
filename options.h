struct Options
{ 
	bool queue;
	bool stack;
  bool output_map;
  bool output_list;
  bool input_map;

};

void initialize_options(Options &options)
{
	options.queue = false;
  options.stack = false;

  options.output_map = false;
  options.output_list = false;
  options.input_map = false;
}

void get_options(Options &options, int argc, char *argv[])
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
        options.stack = true;
        break;
        
      case 'q':
        options.queue = true;
        break;
        
      case 'o':
        alg_opt = optarg;
        if(alg_opt == "M") options.output_map = true;
        else if (alg_opt == "L") options.output_list = true;
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

void check_options(Options &options)
{
  if (options.stack && options.queue) 
  	error("Incorrect arguments. Cannot declare stack and queue.", 1);
  else if ((!options.stack) && (!options.queue)) 
  	error("Incorrect arguments. Must declare stack or queue.", 1);

  if((!options.output_list) && (!options.output_map)) 
  	options.output_map = true;
}

void set_options(Options &options, int argc, char *argv[])
{
	initialize_options(options);
	get_options(options, argc, argv);
	check_options(options);
}
