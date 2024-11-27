#ifndef PUZZLE_H
#define PUZZLE_H

#include <array>

// should prolly move to a globals.h file
constexpr int row    {4};
constexpr int column {4};
constexpr int nboxes {row*column};

enum InitType
{
  trivial,
  reverseTrivial,
  horizSwap,
  vertSwap,
  randomOrder,
};

class Puzzle
{
public:
  Puzzle(InitType initChoice);
  Puzzle();
  
  void print_boxes() const;
  
private:
  std::array<int,nboxes> boxes {};
  std::array<int,nboxes> init_boxes(InitType initChoice);
};

// with C-style array
class PuzzleC
{
public:
  int init_boxes()
  {
    // not allowed
    // return {1 , 2 , 3 , 4 ,
    // 	       5 , 6 , 7 , 8 ,
    // 	       9 , 10, 11, 12,
    // 	       13, 14, 15, 16};
  }
  
  PuzzleC (InitType initChoice) 
  {
    // ?
  }
  
private:
  int boxes[nboxes];
};

#endif
