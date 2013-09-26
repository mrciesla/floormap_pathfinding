void print_help()
{
   cout << "\nProject 1 - Back to the Ship!" << endl; 
   cout << "             A path-finding algorithm \n\n"
        << endl;
        
   cout << "       -s, --stack\n"
        << "              find path using stack\n\n"
        << "       -q, --queue\n"
        << "              find path using queue\n\n"
        << "       -o, --output (M|L)\n"
        << "              output a map (M) or list (L)\n\n"
        << "       -h, --help\n"
        << "              display this help and exit\n\n"
        << endl;          
}

void error(string error_message, int exit_type)
{ 
  cerr << "Error: " << error_message 
       << " Exiting program." << endl;
	exit(exit_type);
}
