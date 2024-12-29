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
    Puzzle puzzle(Puzzle::randomOrder);
    
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

    // a few ideas for how this should look like in the future
    // while(!puzzle)
    // {
    //     cout << puzzle;
    //     cin >> inputHandler >> puzzle;
    //     // puzzle.update_status(); // move this into push function
        
    //     /*  inputHandler should contain a dictionary turning 'wasd' characters
    //      *  into characters for the switch inside puzzle.  The dictionary will
    //      *  be hard-coded.  The whole thing will be string-based/stream-based
    //      *  and will allow for simple undoing and redoing.  The inputHandler
    //      *  will take care of recording a history in order to feed the correct
    //      *  characters to puzzle.  'u' and 'r' will be used for undo and redo
    //      *  respectively.
    //      */ 
    // }
}
