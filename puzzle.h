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
    // constructors
    Puzzle(InitType initChoice);
    Puzzle();

    // status methods
    int  current_box() const;
    bool is_solved() const;
    void update_status();
    void quit();

    // movement methods
    void push_up();
    void push_down();
    void push_left();
    void push_right();

    // debug methods
    // void print_boxes() const;
    bool two_boxes_are_equal() const;
    bool max_too_high() const;
    bool min_too_low() const;

    // do these as non-friend functions, it will be possible by using getters and setters
    // friend std::ostream& operator<<(std::ostream& out, const Puzzle puzzle);
    // friend std::istream& operator>>(std::istream& in ,       Puzzle puzzle);

    const int& operator[] (int i) const;
    const int& operator() (int i, int j) const;
    operator bool() const;
    
private:
    std::array<int,nboxes> boxes {};
    int  m_currentBox {};
    
    bool m_is_solved {false};
    bool m_quit {false};

    // private init methods
    std::array<int,nboxes> init_boxes(InitType initChoice);
    int init_current_box();

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
