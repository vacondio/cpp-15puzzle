#include "input_handler.h"
#include "puzzle.h"
#include <array>
#include <iostream>
#include <utility>
#include <string>
#include <string_view>
#include <unordered_map>
// #include <cstddef>

namespace Input
{
    using namespace std::string_view_literals;
    const std::unordered_map puzzleMappings { std::pair{"w"sv,'u'},
                                              std::pair{"a"sv,'l'},
                                              std::pair{"s"sv,'d'},
                                              std::pair{"d"sv,'r'},
                                              std::pair{"q"sv,'q'} };
}

int main()
{
    // Puzzle puzzle(); // this is to test delegating of constructor
    // Puzzle puzzle(InitType{trivial});
    // Puzzle puzzle(InitType{reverseTrivial});
    // Puzzle puzzle(InitType{horizSwap});
    // Puzzle puzzle(InitType{vertSwap});
    // Puzzle puzzle(InitType{randomOrderDumber});
    // Puzzle puzzle(InitType{randomOrderDumb});
    InputHandler inputHandler(Input::puzzleMappings);
    Puzzle       puzzle(Puzzle::randomOrder);

    #ifndef NDEBUG
    std::cout << "Program was compiled in debug mode\n";
    #endif
    
    while(!puzzle)
    // for (int i=0; i<2; ++i)
    {
        #ifndef NDEBUG
        std::cout << "Empty cell in 1D is " << puzzle.empty_cell_1d() << "\n";
        std::cout << "Empty cell in 2D is " << puzzle.empty_cell_2d().i
                  << ", "                   << puzzle.empty_cell_2d().j << "\n";
        std::cout << "Empty cell holds "    << puzzle(puzzle.empty_cell_2d().i,
                                                      puzzle.empty_cell_2d().j) << "\n";
        #endif
        
        std::cout << puzzle;
        std::cin >> inputHandler >> puzzle;

        // std::string outstring {};
        // std::cin >> inputHandler;
        // std::cout << "Translated string: " << inputHandler << '\n';
        
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
