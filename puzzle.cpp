#include "puzzle.h"
// #include <array>
#include <cstddef>
#include <iostream>

Puzzle::Puzzle(InitType initChoice)
  : boxes { init_boxes(initChoice) } {}

Puzzle::Puzzle() : Puzzle (InitType{trivial}) {}

void Puzzle::print_boxes() const
{
  for(std::size_t i{0}; i<nboxes; ++i)
    {
      std::cout << boxes[i];
      if ((i+1)%4 == 0) std::cout << "\n";
      else std::cout << "\t";
    }
}

std::array<int,nboxes> Puzzle::init_boxes(InitType initChoice)
{
  std::array<int,nboxes> tmp {};

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
      case randomOrder:
      default:
        break;
  }  
  return tmp;

  // return {1 , 2 , 3 , 4 ,
  //         5 , 6 , 7 , 8 ,
  //         9 , 10, 11, 12,
  //         13, 14, 15, 16}; /* bad practice to return
  //                             but we'll do it for the sake of learning */
}
