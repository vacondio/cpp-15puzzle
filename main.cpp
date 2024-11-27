#include "puzzle.h"
#include <array>
#include <iostream>
// #include <cstddef>

int main()
{
  // Puzzle puzzle { InitType{trivial} };
  Puzzle puzzle {}; // this is to test delegating of constructor
  puzzle.print_boxes();

  std::cout << "\n" << "Hello world!\n";
  return 0;
}
