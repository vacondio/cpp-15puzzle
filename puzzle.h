#ifndef PUZZLE_H
#define PUZZLE_H

#include <array>
#include <iostream>

constexpr int nRows  { 4 };
constexpr int nCols  { 4 };
constexpr int nCells { nRows*nCols };


class Puzzle
{
public:
    // data types
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

    enum PushDirection
    {
        up,
        down,
        left,
        right,
    };

    struct ArrayIdx2D
    {
        int i {};
        int j {};
    };

    // constructors
    Puzzle(InitType initChoice);
    Puzzle();

    // status methods
    int        empty_cell_1d() const;
    ArrayIdx2D empty_cell_2d() const;
    bool       is_solved() const;
    void       update_status();
    void       quit();

    // movement method
    void push(char dir);

    // debug methods
    bool two_cells_are_equal() const;
    bool max_too_high() const;
    bool min_too_low() const;


    // member operator overloads
    const int& operator[] (int i) const;
    const int& operator() (int i, int j) const;
    operator bool() const;
    
private:
    std::array<int,nCells> m_cells {};

    int        m_emptyCell1D {};
    ArrayIdx2D m_emptyCell2D {};
    
    bool m_is_solved {false};
    bool m_quit {false};

    // private init methods
    std::array<int,nCells> init_cells(InitType initChoice);
    int        init_empty_cell_1d();
    ArrayIdx2D init_empty_cell_2d();
};

// non-member operator overloads
std::ostream& operator<<(std::ostream& out, const Puzzle& puzzle);
std::istream& operator>>(std::istream& in,        Puzzle& puzzle);

#endif
