#include "puzzle.h"
#include <array>
#include <iostream>
// #include <cstddef>

int main()
{
    // Puzzle puzzle(); // this is to test delegating of constructor
    // Puzzle puzzle(InitType{trivial});
    Puzzle puzzle(InitType{reverseTrivial});
    // Puzzle puzzle(InitType{horizSwap});
    // Puzzle puzzle(InitType{vertSwap});
    // Puzzle puzzle(InitType{randomOrderDumber});
    // Puzzle puzzle(InitType{randomOrderDumb});
    // Puzzle puzzle(InitType{randomOrder});
  
    // puzzle.print_boxes();

    
    while(!puzzle)
    {
        // debug
        std::cout << "Current box in 1D is " << puzzle.current_box_1d() << "\n";
        std::cout << "Current box in 2D is " << puzzle.current_box_2d().i
                  << ", "                    << puzzle.current_box_2d().j << "\n";
        std::cout << "Current box holds " << puzzle(puzzle.current_box_2d().i,
                                                    puzzle.current_box_2d().j) << "\n";
        // production
        std::cout << puzzle;  // overload << operator
        std::cin  >> puzzle;  // overload >> operator (needs input validity check)
        puzzle.update_status();
    }
    return 0;
}
