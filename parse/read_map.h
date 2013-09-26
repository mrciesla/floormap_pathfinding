bool is_valid_line(string l) //Checks if a line is valid input:
{  
	string slash("/");

	if(l == "") return false;   
	else if (l.length() == 1) error("Line size too small.", 1);
	else if(l[0] == slash[0]) 
	{  
	  if(l[1] == slash[0]) return false;
	  else error("Invalid symbol", 1);
	}
	else return true;
}



bool is_in_spaceship(Game &game, Coordinate coord)
{  if((coord.x >= 0) && (coord.x < game.size_floors) && 
      (coord.y >= 0) && (coord.y < game.size_floors) &&
      (coord.f >= 0) && (coord.f < game.num_floors)) return true;
   else return false;
}


int next_comma_index(string l)
{  string comma(",");
   for (int i = 0; i < l.length(); i++)
   {  if(l[i] == comma[0]) return i;
   }

}


Coordinate get_coordinate(string l)
{  Coordinate c;
   //get values first, then error check
   l.erase(l.begin()); //Delete begin paren
   l.erase(l.end() - 1); //Delete end paren
   
   
   //x
   int nc = next_comma_index(l);
   //string lx = l.substr(0,nc);
   c.y = atoi((l.substr(0,nc)).c_str());
   l.erase(0, nc + 1);
   
   //y
   nc = next_comma_index(l);
  // string ly = l.substr(0,nc);
   c.x = atoi((l.substr(0,nc)).c_str());
   l.erase(0, nc + 1);
   
   //f
   nc = next_comma_index(l);
   //string lf = l.substr(0,nc);
   c.f = atoi((l.substr(0,nc)).c_str());
   l.erase(0, nc + 1);
   
   bool symbolValid = false;
   //Checking for floor tile type
   for(int nT = 0; nT < floor_type.length(); nT++)
   {
      if(l[0] == floor_type[nT])
      {  c.t = nT;
         symbolValid = true; 
      }
   }
   if(!symbolValid) error("Invalid symbol in input.", 1);
   
   return c;
}




void read_list_file(Game &game)
{
	string line;
	for(int f_num = 0; f_num < game.num_floors; f_num++)
       {  for(int y_num = 0; y_num < game.size_floors; y_num++)
          {  for(int x_num = 0; x_num < game.size_floors; x_num++)
             {  game.map[f_num][y_num][x_num].t = OK;
                game.map[f_num][y_num][x_num].visited = false;
             }
          }
       } //initializing to OK

     
     while (getline(cin, line))
     {  if (is_valid_line(line))//If the line is valid
        {  Coordinate c = get_coordinate(line);
           if (is_in_spaceship(game, c))
           {  //ok
              if (c.t == OK) 
              {//do nothing
              }

              //wall
              else if (c.t == WALL)
              {  game.map[c.f][c.x][c.y].t = WALL;
              }
              
              //beam
              else if (c.t == HANGAR)
              {  game.hangar.t = HANGAR;
                 game.hangar.f = c.f;
                 game.hangar.x = c.x;
                 game.hangar.y = c.y;
                 game.map[c.f][c.x][c.y].t = HANGAR;
              }
              
              //start
              else if (c.t == START)
              {  game.start.t = START;
                 game.start.f = c.f;
                 game.start.x = c.x;
                 game.start.y = c.y;
                 game.map[c.f][c.x][c.y].t = START;
              }
              
              //number, so tile is just c.t
              else
              {  game.map[c.f][c.x][c.y].t = c.t;
              }
           
           }
           
           else error("Coordinate not in building.", 1);
        }
     }


}



void read_map_file(Game &game)
{  
	string line;

  int f_num = (game.num_floors - 1), y_num = 0, line_num = 0;
  while((line_num < (game.num_floors * game.size_floors)))
  {
    if(y_num == game.size_floors)//Going to next floor? Reset the Y coord
    {  
    	y_num = 0;
      f_num--;
    }

     if(cin.fail()) error("Too few lines.", 1);
     
     getline(cin, line);
     
     if(line.length() == 1) error("Line can't have length of 1.", 1);

     if (is_valid_line(line)) //If the line is valid
     {  if (line.length() < game.size_floors) error("Too few characters in line.", 1);
        
        line_num++;
        
        if(y_num < game.size_floors)
        {  
           for(int x_num = 0; x_num < game.size_floors; x_num++)
           { 
              bool valid_symbol = false;
              //Checking for floor tile type
              for(int t_num = 0; t_num < floor_type.length(); t_num++)
              {
                 if(line[x_num] == floor_type[t_num])
                 {  game.map[f_num][x_num][y_num].t = t_num;
                    game.map[f_num][x_num][y_num].visited = false; 
                    valid_symbol = true; 
                 }
              }
              if(!valid_symbol) error("Invalid symbol in input." , 1);

              //Set start position
              if (line[x_num] == floor_type[START])
              {  game.start.t = START;
                 game.start.f = f_num;
                 game.start.x = x_num;
                 game.start.y = y_num;
              }
              //Set beam position
              if (line[x_num] == floor_type[HANGAR])
              {  game.hangar.t = HANGAR;
                 game.hangar.f = f_num;
                 game.hangar.x = x_num;
                 game.hangar.y = y_num;
              }
           }
        }

        y_num++;
     }
  }
}