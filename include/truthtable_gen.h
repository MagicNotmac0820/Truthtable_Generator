#ifndef __TRUTHTABLE_GEN_H__
#define __TRUTHTABLE_GEN_H__

/**
 * This is a generator of truth table and boolean function
 * The user have to handle the input, make sure the number of boolean variables matching the boolean function
 */

#include <vector>

class Generator{
    private :
        std::vector<char> variableTypes ;
        bool (*func)( const std::vector<bool> &inputs ) ;
        std::vector<std::vector<bool>> result ;

        void backtrack( int index , std::vector<std::vector<bool>> &result , std::vector<bool> &path ) ;
        std::vector<std::vector<bool>> generate( int variablesNum ) ;
    public :
        Generator( int variablesNum , bool (*func)( const std::vector<bool> &inputs ) ) ;
        void print(void) ;
} ;

#endif  //__TRUTHTABLE_GEN_H__