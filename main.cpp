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
}
