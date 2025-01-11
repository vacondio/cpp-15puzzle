#include "puzzle.h"
#include <unordered_map>
#include <utility>

namespace Input
{
    using namespace std::string_view_literals;
    inline const std::unordered_map puzzleMappings { std::pair{"w"sv,'u'},
                                                     std::pair{"a"sv,'l'},
                                                     std::pair{"s"sv,'d'},
                                                     std::pair{"d"sv,'r'},
                                                     std::pair{"q"sv,'q'} };
}
