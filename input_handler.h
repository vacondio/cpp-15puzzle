#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <iostream>
#include <limits> // for std::numeric_limits
#include <sstream>
#include <unordered_map>
//#include <string> // in case we want to use std::char_traits<char>::eof

class InputHandler
{
public:
    // constructors
    InputHandler(std::unordered_map<std::string_view,char> dict, char delim='\n');
    // InputHandler(const std::array<T>& keysm const std::array<U>& items, char delim);

    // getters
    const std::unordered_map<std::string,int>& get_dict() const;
    // when a template, it will be
    // const std::unordered_map<T,U>& get_dict() const;
    
    // operator overloads
    friend std::stringstream& operator>>(std::istream&, InputHandler&);
    friend std::ostream&      operator<<(std::ostream&, InputHandler&);

private:
    std::unordered_map<std::string_view,char> m_dict {};
    const char                                m_delim {};
    std::stringstream                         m_translatedStream {};

    // private methods
    void clean_istream(std::istream&);
    //
    // when a template it will be
    // std::unordered_map<T,U> m_dict {};
    // void clean_stream(V) // V allowed to be only a class derived from basic_istream
};

#endif
