/*******************************************************************************
Colleen Sain
EECS 281 - Project 1
Last Modified: 1/20/2013

g++ p1.cpp
./a.out --queue < testM_nesw.txt
./a.out --stack < testM.txt > testOut.txt

dos2unix -U *; tar czf ./submit.tar.gz *.cpp *.h Makefile test*.txt

reread spec about elevator
so, if I pop off an elevator I CAN look around, yes? Or...what?
Also, why is QUEUE working, but not stack??
check is_in_building and can_move for weird behavior with moving between floors

*******************************************************************************/
#include <cstdlib>
#include <iostream>
#include <getopt.h>

// #include <fstream>
// #include <cassert>
// #include <iomanip>

#include <string>
#include "p1.h"

using namespace std;

int main(int argc, char *argv[])
{
  Options options;
  set_options(options, argc, argv);

  SpaceShip ss;
  read_header_info(ss, options);

  Path ***ship_map;
  ship_map = new Path**[ss.num_floors];

  for (int i = 0; i < ss.num_floors; ++i)
  {  
    ship_map[i] = new Path*[ss.size_floors];

    for (int j = 0; j < ss.size_floors; ++j)
      ship_map[i][j] = new Path[ss.size_floors];     
  }

  string line;
  if (options.input_map) 
    read_map_file(ss, options, ship_map);
  else 
    read_list_file(ss, options, ship_map);

  // Print the original map:
  cout << "orig map" << endl;
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

  cout << "map info" << endl;
  print_coord(ss.start, "start");
  print_coord(ss.hangar, "hangar");
  cout << "------------------------" << endl;
   
  Stack<Coordinate> stack_list;
  Queue<Coordinate> queue_list;
  bool found_hangar = false;  
  find_hangar(ss, options, ship_map, stack_list, queue_list, found_hangar);

  Stack<Coordinate> path_taken; 
  Coordinate c;

  int path_length = 1;
  if (found_hangar) 
    retrace_path(ss, options, ship_map, path_taken, path_length, c);

  cout << ss.size_floors << "\n" << ss.num_floors << endl;
  if(!options.output_map)
    print_list(path_taken, path_length, c);

  else
    print_map(ss, options, ship_map, path_taken, path_length, c);

  for (int i = 0; i < ss.num_floors; ++i)
    for (int j = 0; j < ss.size_floors; ++j) delete [] ship_map[i][j];

  return 0;
}
