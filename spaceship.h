enum FloorType
{   
  L0,
  L1,
  L2,
  L3,
  L4,
  L5,
  L6,
  L7,
  L8,
  L9,
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

//tileType
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

struct SpaceShip
{  int num_floors;
   int size_floors;
   Coordinate start;
   Coordinate hangar;
   Coordinate hangar_adj;
   
   Coordinate cur;
   Coordinate prev;
};


struct Path
{  int t;
   bool visited;

   Coordinate from_coord;
   int from_direction;
};

const int COMPASS[4][3] = { {  0, -1, NORTH },
                            {  1,  0,  EAST },
                            {  0,  1, SOUTH },
                            { -1,  0,  WEST } };