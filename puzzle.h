#ifndef PUZZLE_H
#define PUZZLE_H

#include <array>
#include <iostream>

// should prolly move to a globals.h file
constexpr int rows    {4};
constexpr int columns {4};
constexpr int nboxes  {rows*columns};

enum InitType
{
    trivial,
    reverseTrivial,
    horizSwap,
    vertSwap,
    randomOrderDumber,
    randomOrderDumb,
    randomOrder,  
};

class Puzzle
{
public:
    Puzzle(InitType initChoice);
    Puzzle();

    // status
    bool is_solved() const;
    void update_status();
    void quit();

    // debug methods
    // void print_boxes() const;
    bool two_boxes_are_equal() const;
    bool max_too_high() const;
    bool min_too_low() const;

    // do these as non-friend functions, it will be possible by using getters and setters
    // friend std::ostream& operator<<(std::ostream& out, const Puzzle puzzle);
    // friend std::istream& operator>>(std::istream& in ,       Puzzle puzzle);

    const int& operator[] (int i) const;
    operator bool() const;
    
private:
    std::array<int,nboxes> boxes {};
    std::array<int,nboxes> init_boxes(InitType initChoice);
    
    bool m_is_solved {false};
    bool m_quit {false};
};

std::ostream& operator<<(std::ostream& out, const Puzzle& puzzle);
// std::istream& operator>>(std::istream& in,        Puzzle& puzzle);

// // with C-style array
// class PuzzleC
// {
// public:
//     int init_boxes()
//     {
//       // not allowed
//       // return {1 , 2 , 3 , 4 ,
//       //         5 , 6 , 7 , 8 ,
//       //         9 , 10, 11, 12,
//       //         13, 14, 15, 16};
//     }
    
//     PuzzleC (InitType initChoice) 
//     {
//       // ?
//     }
    
// private:
//     int boxes[nboxes];
// };

#endif
