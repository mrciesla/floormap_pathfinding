struct Options
{ 
	bool queue;
	bool stack;
  bool output_map;
  bool output_list;
  bool input_map;

};

enum FloorType
{ 
  F0,
  F1,
  F2,
  F3,
  F4,
  F5,
  F6,
  F7,
  F8,
  F9,  
  OK,
  WALL,
  HANGAR,
  START,
  NORTH,
  SOUTH,
  EAST,
  WEST,
  ELEVATOR
};

const string floor_type("0123456789.#HSnsewE");

struct Coordinate
{  
  int x; // row
  int y; // col
  int f; // floor number
  int t; // floor TYPE
};

void print_coord(Coordinate coord, string message = "")
{
  cout << "(f,x,y,t) --> ("
       << coord.f << ","
       << coord.x << ","
       << coord.y << ","
       << coord.t << ")    " 
       << message << endl;
}


struct FloorTile
{  int t;
   bool visited;

   Coordinate from_coord;
   int from_direction;
};

const int COMPASS[4][3] = { {  0, -1, NORTH },
                            {  1,  0,  EAST },
                            {  0,  1, SOUTH },
                            { -1,  0,  WEST } };

struct Game
{
	Options options;
  int num_floors;
  int size_floors;
  Coordinate start;
  Coordinate hangar;
  Coordinate hangar_adj;

  Coordinate cur;
  Coordinate prev;

  stack<Coordinate> stack_list;
  queue<Coordinate> queue_list;

  stack<Coordinate> path_taken; 
  Coordinate path_coord;
  int path_length;

  bool found_hangar;

	FloorTile ***map;
};