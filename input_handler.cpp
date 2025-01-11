#include "input_handler.h"
#include <cassert>
#include <iostream>
#include <limits> // for std::numeric_limits
#include <sstream>
#include <unordered_map>
#include <cstdlib>
//#include <string> // in case we want to use std::char_traits<char>::eof

InputHandler::InputHandler(std::unordered_map<std::string_view,char> dict,
                           char delimIn, char delimOut)
    : m_translatedStream {}
    , m_dict     { dict }
    , m_delimIn  { delimIn }
    , m_delimOut { delimOut } {}

std::stringstream& operator>>(std::istream& in, InputHandler& inputHandler)
{
    // clean_sstream(m_translatedStream);
    const char delimIn  {inputHandler.m_delimIn};
    const char delimOut {inputHandler.m_delimOut};
    
    std::string currentWord {};
    std::string translatedStrUnit {};
    std::string translatedString {};

    while (true)
    {
        // consider handling this also in production
        assert(in && "InputHandler: in is in failstate\n");

        in >> currentWord;
        while(in.peek() == ' ') in.get(); // eat whitespace (but not '\n')
        
        if (inputHandler.m_dict.contains(currentWord))
        {
            std::stringstream translatedWord {};
            translatedWord << inputHandler.m_dict[currentWord];
            translatedWord >> translatedStrUnit;
            translatedString += translatedStrUnit + ' ';
        }
        else
        {
            in.ignore(std::numeric_limits<std::streamsize>::max(), delimIn);
            break; // exit as soon as invalid input is encountered...
        }

        if (in.peek() == delimIn)
        {
            in.get();
            break; // ... or if delimiter is reached
        }
    }
    translatedString += delimOut; // add delimiter to translated string
    
    inputHandler.m_translatedStream.str(std::move(translatedString));
    // clean_istream(in);
    
    return inputHandler.m_translatedStream;
}

std::ostream& operator<<(std::ostream& out, InputHandler& inputHandler)
{
    // // doing as follows destroys the content, which we do not actually want
    // std::string outstr {};
    // std::getline(inputHandler.m_translatedStream, outstr);
    // out << outstr;

    // this creates a copy of the underlying string instead
    out << inputHandler.m_translatedStream.str();
    
    return out;
}

void InputHandler::clean_istream(std::istream& istream)
{
    istream.clear();
    istream.ignore(std::numeric_limits<std::streamsize>::max(), m_delimIn);
    //
    // // alternatively
    // while (!istream.eof())
    //     istream.get();
    // istream.clear();
    //
    // // if we do not want to end up with a failbit
    // while (istream.peek() != std::char_traits<char>::eof())
    //     istream.get();
    //
    // // these are all less performant alternatives, although simpler to write
    //
}


/* how the stream-based history should work
 *
 * - when undo is entered:
 *   + pop one character from undoHist
 *   + put one character into redoHist
 *
 * - when redo is entered:
 *   + pop one character from redoHist
 *   + put one character back into undoHist
 *
 * foo hello world hi there
 */

/* From learncpp.com:
 * https://www.learncpp.com/cpp-tutorial/overloading-operators-using-member-functions/
 *
 * The following rules of thumb can help you determine which form is best for a
 * given situation:
 *
 * - If you’re overloading assignment (=), subscript ([]), function call (()),
 *   or member selection (->), do so as a member function.
 *
 * - If you’re overloading a unary operator, do so as a member function.
 *
 * - If you’re overloading a binary operator that does not modify its left
 *   operand (e.g. operator+), do so as a normal function (preferred) or friend
 *   function.
 *
 * - If you’re overloading a binary operator that modifies its left operand, but
 *   you can’t add members to the class definition of the left operand
 *   (e.g. operator<<, which has a left operand of type ostream), do so as a
 *   normal function (preferred) or friend function.
 *
 * - If you’re overloading a binary operator that modifies its left operand
 *   (e.g. operator+=), and you can modify the definition of the left operand,
 *   do so as a member function.
 */              
