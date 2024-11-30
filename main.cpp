#include "puzzle.h"
#include <array>
#include <iostream>
// #include <cstddef>

int main()
{
    // Puzzle puzzle {}; // this is to test delegating of constructor
    //Puzzle puzzle { InitType{trivial} };
    // Puzzle puzzle { InitType{reverseTrivial} };
    // Puzzle puzzle { InitType{horizSwap} };
    // Puzzle puzzle { InitType{vertSwap} };
    // Puzzle puzzle(InitType{randomOrderDumb});
    Puzzle puzzle(InitType{randomOrder});
  
    puzzle.print_boxes();
  
    if (puzzle.two_boxes_are_equal())
        std::cout << "There are two equal boxes, alas!\n";
    else
        std::cout << "There are no two equal boxes, hooray!\n";
  
    if (puzzle.max_too_high())
        std::cout << "Max val is too high, alas!\n";
    else
        std::cout << "Max val is fine, hooray!\n";
  
    if (puzzle.min_too_low())
        std::cout << "Min val is too low, alas!\n";
    else
        std::cout << "Min val is fine, hooray!\n";
  
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
