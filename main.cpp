#include "puzzle.h"
#include <array>
#include <iostream>
// #include <cstddef>

int main()
{
    // Puzzle puzzle(); // this is to test delegating of constructor
    // Puzzle puzzle(InitType{trivial});
    // Puzzle puzzle(InitType{reverseTrivial});
    // Puzzle puzzle(InitType{horizSwap});
    // Puzzle puzzle(InitType{vertSwap});
    // Puzzle puzzle(InitType{randomOrderDumber});
    // Puzzle puzzle(InitType{randomOrderDumb});
    Puzzle puzzle(InitType{randomOrder});
    
    while(!puzzle)
    {
        // debug
        std::cout << "Empty cell in 1D is " << puzzle.empty_cell_1d() << "\n";
        std::cout << "Empty cell in 2D is " << puzzle.empty_cell_2d().i
                  << ", "                   << puzzle.empty_cell_2d().j << "\n";
        std::cout << "Empty cell holds "    << puzzle(puzzle.empty_cell_2d().i,
                                                      puzzle.empty_cell_2d().j) << "\n";
        // production
        std::cout << puzzle;
        std::cin  >> puzzle;
        puzzle.update_status();
    }
    return 0;
}
