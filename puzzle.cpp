#include "puzzle.h"
// #include <array>
#include <cstddef>
#include <iostream>
#include <random>

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
        {
          // random generation shall be made smarter
          std::random_device rd;
          std::mt19937 gen(rd());
          std::uniform_int_distribution<> distrib[nboxes]{};
          
          for (int i{0}; i<nboxes; ++i)
            {
              distrib[i] = std::uniform_int_distribution<>(1,nboxes-i);
            }
          // // debug
          // for (int i{0}; i<nboxes; ++i)
          //   std::cout << distrib[i](gen) << "\n";
        
          for (int i{0}; i<nboxes; ++i)
          {
            int num  {distrib[i](gen)};
            int num_ {num};
            for (int j{0}; j<i; ++j)
              {
              if (num >= tmp[j])
                {
                  num_ = num;
                  ++num;
                  // once it is increased, we should check again starting from
                  // tmp[0], but doing so causes an infinite loop
                }
              }
            tmp[i] = num;
          }
        }
        break;
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
