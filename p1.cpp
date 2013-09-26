#include <cstdlib>
#include <iostream>
#include <getopt.h>
#include <string>
#include <stack>
#include <queue>
#include "p1.h"
#include "init/errors.h"
#include "init/game.h"
#include "init/options.h"
#include "init/read_header_info.h"
#include "init/init.h"
#include "parse/read_map.h"
#include "parse/parse_input.h"
#include "algo/find_hangar.h"
#include "algo/retrace_path.h"
#include "results/print.h"
#include "results/clean_up.h"

using namespace std;

int main(int argc, char *argv[])
{
  Game game;
  init(game, argc, argv);
  parse_input(game);
  find_hangar(game);
  retrace_path(game);
  print_results(game);
  clean_up(game);
  return 0;
}
