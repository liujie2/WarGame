#ifndef STDTOSTRING_H
#define STDTOSTRING_H
/*
#include <string>
#include <sstream>

using namespace std;
namespace std
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
    
    inline int stoi(const std::string &s, size_t *idx = 0, int base = 10)
    {
        char *endptr = 0;
        int v = strtol(s.c_str(), &endptr, base);
        if (idx) {
            *idx = endptr - s.c_str();
        }
        return v;
    }
}
*/
#endif