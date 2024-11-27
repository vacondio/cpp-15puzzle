#include "puzzle.h"
#include <array>
#include <iostream>
// #include <cstddef>

int main()
{
  // Puzzle puzzle {}; // this is to test delegating of constructor
  Puzzle puzzle { InitType{trivial} };
  // Puzzle puzzle { InitType{reverseTrivial} };
  // Puzzle puzzle { InitType{horizSwap} };
  // Puzzle puzzle { InitType{vertSwap} };
  // Puzzle puzzle { InitType{randomOrder} };

  puzzle.print_boxes();

  std::cout << "\n" << "Hello world!\n";
  return 0;

  // Pseudo-code for the game
  // print welcome message
  // loop : while(true)
  //   print puzzle : cout << puzzle;
  //   read move from user : cin >> puzzle;
  //   until puzzle is solved : if (puzzle) break
  // endloop
  // congratulate user and quit
  //
  // that'll roughly translate to:
  // std::cout << "Welcome to 15puzzle:";
  // while(true)
  //   {
  //     cout << puzzle;
  //     cin  >> puzzle; //needs input validity checks
  //     if (puzzle) break;
  //   }
}
