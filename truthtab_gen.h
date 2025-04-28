#ifndef __TRUTHTAB_GEN_H__
#define __TRUTHTAB_GEN_H__

/**
 * This is a generator of truth table and boolean function
 * The user have to handle the input, make sure the number of boolean variables matching the boolean function
 */

#include <iostream>
#include <vector>
using std::cin ;
using std::cout ;
using std::endl ;
using std::vector ;

class Generator{
    private :
        vector<char> variableTypes ;
        bool (*func)( const vector<bool> &inputs ) ;
        vector<vector<bool>> result ;

        void backtrack( int index , vector<vector<bool>> &result , vector<bool> &path ) ;
        vector<vector<bool>> generate( int variablesNum ) ;
    public :
        Generator( int variablesNum , bool (*func)( const vector<bool> &inputs ) ) ;
        void print(void) ;
} ;

Generator::Generator( int variablesNum , bool (*func)( const vector<bool> &inputs ) ) :
                      func(func)
{
    variableTypes.resize(variablesNum) ;
    cout << "Please input the types of your all variables: " ;
    for( char &typeName : variableTypes )
        cin >> typeName ;

    result = generate(variablesNum) ;
}

void Generator::backtrack( int index , vector<vector<bool>> &result , vector<bool> &path ){
    int variablesNum = path.size()-1 ;
    if( index == variablesNum ){
        path[variablesNum] = func(vector<bool> ( path.begin() , path.begin()+variablesNum )) ;
        result.push_back(path) ;
        return ;
    }

    path[index] = false ;
    backtrack( index+1 , result , path ) ;
    path[index] = true ;
    backtrack( index+1 , result , path ) ;
}

vector<vector<bool>> Generator::generate( int variablesNum ){
    vector<vector<bool>> result ;
    vector<bool> path(variablesNum+1) ;

    backtrack( 0 , result , path ) ;
    return result ;
}

void Generator::print(void){
    for( const char &typeName : variableTypes )
        cout << typeName << ' ' ;
    cout << 'F' << endl ;

    for( const vector<bool> &vec : result ){
        for( const bool &element : vec )
            cout << element << ' ' ;
        cout << endl ;
    }   

    return ;
}

#endif  //__TRUTHTAB_GEN_H__