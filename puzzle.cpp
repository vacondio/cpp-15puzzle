#include "puzzle.h"
#include "Random.h"
#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

// constructors
Puzzle::Puzzle(InitType initChoice)
    : m_cells       { init_cells(initChoice) }
    , m_emptyCell1D { init_empty_cell_1d() }
    , m_emptyCell2D { init_empty_cell_2d() } {}

Puzzle::Puzzle() : Puzzle (InitType{randomOrder}) {}

// status methods
int Puzzle::empty_cell_1d() const
{
    return m_emptyCell1D;
}

Puzzle::ArrayIdx2D Puzzle::empty_cell_2d() const
{
    return m_emptyCell2D;
}

bool Puzzle::is_solved() const
{
    return m_is_solved;
}

void Puzzle::update_status()
{
    for(int i{0}; i<nCells-1; ++i)
    {
        if (m_cells[i]>m_cells[i+1]) return;
    }
    m_is_solved = true;
    m_quit = true;
}

void Puzzle::quit()
{
    m_quit = true;
}

// movement method
void Puzzle::push(char dir)
{
    int iTarget { m_emptyCell2D.i };
    int jTarget { m_emptyCell2D.j };
    
    int iStart  {};
    int jStart  {};

    switch(dir)
    {
    case 'w':
        iStart = iTarget + 1;
        jStart = jTarget    ;
        if (iStart > nRows-1) return;
        break;

    case 's':
        iStart = iTarget - 1;
        jStart = jTarget    ;
        if (iStart < 0) return;
        break;

    case 'a':
        iStart = iTarget    ;
        jStart = jTarget + 1;
        if (jStart > nCols-1) return;
        break;

    case 'd':
        iStart = iTarget    ;
        jStart = jTarget - 1;
        if (jStart < 0) return;
        break;

    case 'q':
        m_quit = true;
        break;
        return;

    default:
        return;
    }

    std::swap(m_cells[ iStart*nCols + jStart ],
              m_cells[iTarget*nCols + jTarget]);
    /* // could also do this if the the operator() overload didn't prevent
     * // modifying boxes:
     * std::swap((*this)(iStart,jStart), (*this)(iTarget,jTarget));*/
    m_emptyCell1D   = iStart*nCols + jStart;
    m_emptyCell2D.i = iStart;
    m_emptyCell2D.j = jStart;
}

// debug methods
bool Puzzle::two_cells_are_equal() const
{
    for (int i{0};   i<nCells; ++i)
    for (int j{i+1}; j<nCells; ++j)
    {
        if (m_cells[i] == m_cells[j])
            return true;
    }
    return false;
}

bool Puzzle::max_too_high() const
{
    for (int i{0}; i<nCells; ++i)
    {
        if (m_cells[i] > nCells)
            return true;
    }
    return false;
}

bool Puzzle::min_too_low() const
{
    for (int i{0}; i<nCells; ++i)
    {
        if (m_cells[i] < 1)
          return true;
    }
    return false;
}

// member operator overloads
const int& Puzzle::operator[] (int i) const
{
    return m_cells[i];
}

const int& Puzzle::operator() (int i, int j) const
{
    return m_cells[i*nRows+j];
}

Puzzle::operator bool() const
{
    if (m_quit) return true;
    else return false;
}

// private init methods
std::array<int,nCells> Puzzle::init_cells(InitType initChoice)
{
    std::array<int,nCells> out {};
    // int out[nCells] {};
  
    switch (initChoice)
    {
    case trivial:
        for (std::size_t i{0}; i<nCells; ++i)
        {
            out[i] = i+1;
        }
        break;
  
    case reverseTrivial:
        for (std::size_t i{0}, j{}; i<nCells; ++i)
        {
            j = nCells-i;
            out[i] = j;
        }
        break;
  
    case horizSwap:
    case vertSwap:
    case randomOrderDumber: {
        // // debug
        // for (int i{0}; i<nCells; ++i)
        //   std::cout << distrib[i](gen) << "\n";
        
        for (int i{0}; i<nCells; ++i)
        {
            int pos   {Random::get(1,nCells-i)};
            int delta {0};
            
            for (int k{0}; k<i; ++k)
            {
                if (pos+delta == out[k])
                {
                    ++delta;
                    k=-1;
                }
             }
            for (int j{0}; j<i; ++j)
            {
                if (pos > out[j])
                {
                    ++delta;
                    for (int k{0}; k<i; ++k)
                    {
                        if (pos+delta == out[k])
                        {
                            ++delta;
                            k=-1;
                        }
                    }
                }
            }
            out[i] = pos+delta;
        }
        break; }
    case randomOrderDumb: {
        std::array<int,nCells> guesses {};
        for (int i{0}; i<nCells; ++i)
            guesses[i] = i+1;

        for (int i{0}; i<nCells; ++i)
        {
            int pos    {Random::get(0,nCells-1-i)};
            int delta  {0};
            int delta1 {0};
            int delta2 {0};

            for (int j{0}; j<pos; ++j)
            {
                if (guesses[j] == 0) ++delta1;
            }
            for (int d{0}; d<=delta1; ++d)
            {
                if (guesses[pos+delta2+d] == 0)
                {
                    ++delta2;
                    --d;
                }
            }
            delta = delta1 + delta2;

            guesses[pos+delta] = 0;
            out[i] = pos+delta+1;
        }
        break; }
    default:
    case randomOrder:
        std::vector<int> guesses(nCells);

        for (int i{1}; auto& guess : guesses)
        {
            guess = i;
            ++i;
        }
        
        for (auto& cell : out)
        {
            int maxIdx { static_cast<int>(guesses.size()-1) };
            int pos    { Random::get(0,maxIdx) };
            cell = guesses[pos];
            guesses.erase(guesses.begin() + pos);
        }
        break;
    }
    // hopefully copy elision is performed here by the compiler
    return out;
}

int Puzzle::init_empty_cell_1d()
{
    for (int i{0}; i<nCells; ++i)
        if (m_cells[i]==nCells) return i;
    return -1;
}

Puzzle::ArrayIdx2D Puzzle::init_empty_cell_2d()
{
    int i { m_emptyCell1D / nCols };
    int j { m_emptyCell1D % nCols };
    return Puzzle::ArrayIdx2D { i, j };
}

// non-member operator overloads
std::ostream& operator<<(std::ostream& out, const Puzzle& puzzle)
{
    for(std::size_t i{0}; i<nCells; ++i)
    {
        // formatting shall be fixed using formatting modifiers
        // we shall get rid of the tab character while doing so
        if (puzzle[i] != nCells)
            out << puzzle[i];
        else
            out << "  ";
            
        if ((i+1)%nCols == 0)
            out << "\n";
        else
            out << "\t";
    }
    return out;
}

std::istream& operator>>(std::istream& in, Puzzle& puzzle)
{
    char inputChar {};
    // while(in)
    // {
        in >> inputChar;
        puzzle.push(inputChar);
    // }
    return in;
}
