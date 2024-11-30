#include "puzzle.h"
// #include <array>
#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

Puzzle::Puzzle(InitType initChoice)
    : boxes { init_boxes(initChoice) } {}

Puzzle::Puzzle() : Puzzle (InitType{trivial}) {}

// will replace with overloading of operator <<
void Puzzle::print_boxes() const
{
    for(std::size_t i{0}; i<nboxes; ++i)
    {
        std::cout << boxes[i];
        if ((i+1)%columns == 0) std::cout << "\n";
        else std::cout << "\t";
    }
}

std::array<int,nboxes> Puzzle::init_boxes(InitType initChoice)
{
    std::array<int,nboxes> tmp {};
    // int tmp[nboxes] {};
  
    switch (initChoice)
    {
    case trivial:
        for (std::size_t i{0}; i<nboxes; ++i)
        {
            tmp[i] = i+1;
        }
        break;
  
    case reverseTrivial:
        for (std::size_t i{0}, j{}; i<nboxes; ++i)
        {
            j = nboxes-i;
            tmp[i] = j;
        }
        break;
  
    case horizSwap:
    case vertSwap:
    case randomOrderDumber:
        // // debug
        // for (int i{0}; i<nboxes; ++i)
        //   std::cout << distrib[i](gen) << "\n";
        
        for (int i{0}; i<nboxes; ++i)
        {
            // random generation shall be made smarter
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib{1,nboxes-i};
            
            int num   {distrib(gen)};
            int delta {0};
            
            for (int k{0}; k<i; ++k)
            {
                if (num+delta == tmp[k])
                {
                    ++delta;
                    k=-1;
                }
             }
            for (int j{0}; j<i; ++j)
            {
                if (num > tmp[j])
                {
                    ++delta;
                    for (int k{0}; k<i; ++k)
                    {
                        if (num+delta == tmp[k])
                        {
                            ++delta;
                            k=-1;
                        }
                    }
                }
            }
            tmp[i] = num+delta;
        }
        break;
    case randomOrderDumb: {
        // // debug
        // for (int i{0}; i<nboxes; ++i)
        //   std::cout << distrib[i](gen) << "\n";
            
        std::array<int,nboxes> guesses {};
        for (int i{0}; i<nboxes; ++i)
            guesses[i] = i+1;

        for (int i{0}; i<nboxes; ++i)
        {
            // random generation shall be made smarter
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib{0,nboxes-1-i};

            int pos    {distrib(gen)};
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
            tmp[i] = pos+delta+1;
        }
        break; }
    default:
    case randomOrder:
        std::vector<int> guesses(nboxes);
        for (int i{0}; i<nboxes; ++i)
            guesses[i] = i+1;
        
        for (int i{0}; i<nboxes; ++i)
        {
            // random generation shall be made smarter
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib{0,nboxes-1-i};

            int pos {distrib(gen)};
            tmp[i] = guesses[pos];
            guesses.erase(guesses.begin() + pos);
            
            // // debug
            // for (int j{0}; j<guesses.size(); ++j)
            // {
            //     std::cout << guesses[j] << "\t";
            // }
            // std::cout << "\n";
        }
        break;
    }
    return tmp;
    // return {1 , 2 , 3 , 4 ,
    //         5 , 6 , 7 , 8 ,
    //         9 , 10, 11, 12,
    //         13, 14, 15, 16}; /* bad practice to return
    //                             but we'll do it for the sake of learning */
}

bool Puzzle::two_boxes_are_equal() const
{
    for (int i{0};   i<nboxes; ++i)
    for (int j{i+1}; j<nboxes; ++j)
    {
        if (boxes[i] == boxes[j])
            return true;
    }
    return false;
}

bool Puzzle::max_too_high() const
{
    for (int i{0}; i<nboxes; ++i)
    {
        if (boxes[i] > nboxes)
            return true;
    }
    return false;
}

bool Puzzle::min_too_low() const
{
    for (int i{0}; i<nboxes; ++i)
    {
        if (boxes[i] < 1)
          return true;
    }
    return false;
}
