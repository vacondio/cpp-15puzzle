// courtesy of learncpp.com

#ifndef RANDOM_H
#define RANDOM_H

#include <chrono>
#include <random>

namespace Random
{
    inline std::mt19937 generate()
    {
        using result_type  = std::seed_seq::result_type;
        using steady_clock = std::chrono::steady_clock;
        
        // seed with clock and 7 random numbers
        std::random_device rd{};
        std::seed_seq ss { static_cast<result_type>(
                           steady_clock::now().time_since_epoch().count()),
                           rd(), rd(), rd(), rd(), rd(), rd(), rd()         };

        return std::mt19937 {ss};
    }    
    inline std::mt19937 mt { generate() };

    // function overloads for generating uniform distribution using the mt seed
    inline int get(int min, int max)
    {
        return std::uniform_int_distribution(min,max)(mt);
    }

    template <typename T>
    T get(T min, T max)
    {
        return std::uniform_int_distribution<T>(min,max)(mt);
    }
    template <typename R, typename S, typename T>
    R get(S min, T max)
    {
        return get<R>(static_cast<R>(min), static_cast<R>(max));
    }
        
}

#endif
