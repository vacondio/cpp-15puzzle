#include "puzzle.h"
#include <array>
#include <iostream>
// #include <cstddef>

int main()
{
    // Puzzle puzzle(); // this is to test delegating of constructor
    Puzzle puzzle(InitType{trivial});
    // Puzzle puzzle(InitType{reverseTrivial});
    // Puzzle puzzle(InitType{horizSwap});
    // Puzzle puzzle(InitType{vertSwap});
    // Puzzle puzzle(InitType{randomOrderDumber});
    // Puzzle puzzle(InitType{randomOrderDumb});
    // Puzzle puzzle(InitType{randomOrder});
  
    // puzzle.print_boxes();

    while(!puzzle)
    {
        std::cout << puzzle;  // overload << operator
        // std::cin  >> puzzle;  // overload >> operator (needs input validity check)
        puzzle.update_status();
    }
        return 0;
}
