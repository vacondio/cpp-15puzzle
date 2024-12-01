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
  
    puzzle.print_boxes();

    // while(true)
    //   {
    //     // cout << puzzle;    // overload << operator
    //     // cin  >> puzzle;    // overload >> operator (needs input validity check)
    //     if (puzzle) break; // can be implemented by adding conversion methods to the class
    //   }
    
    // return 0;
  
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
    //     cout << puzzle;    // overload << operator
    //     cin  >> puzzle;    // overload >> operator (needs input validity check)
    //     if (puzzle) break; // can be implemented by adding conversion methods to the class
    //   }
    //
    /* TODO LIST
     *
     * - wrap random number generation in a class (perhaps following
     *   learncpp.com's lesson)
     *
     * - allow for initialization choice via command line arguments
     *
     * - add movement methods to Puzzle class
     *
     * - make commented code above work
     *
     * REMARKS
     *
     * There are currently two random generation algorithms for the initial
     * puzzle: randomOrder and randomOrderDumb.
     *
     * randomOrder makes use of a very straightforward method based on
     * std::vector; whereas randomOrderDumb is based on std::array, avoiding
     * dynamic memory allocation.  In both cases a random number i is generated
     * to extract the integer in the i-th position inside the {1 ... 16} array.
     * While randomOrder just removes the extracted number from the array,
     * randomOrderDumb has to make sure at every extraction that previously
     * extracted numbers are not re-extracted, since its array cannot be
     * resized.  The latter algorithm scales horribly, becoming way more
     * expensive than the former for larger puzzles.
     *
     * Now that I think about it, starting from another fixed {1 ... 16} array
     * and setting the extracted numbers to zero could make the algorithm
     * faster. I should try this and see whether it is still way worse than the
     * std::vector-based one.
     *
     * QUICK NOTE: the new algorithm was just added and is the new
     * randomOrderDumb, and looks much faster. Old dumb algorithm is now
     * randomOrderDumber.
    */
}
