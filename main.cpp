#include "truthtable_gen.h"

bool boolFunc( const vector<bool> &inputs ){
    bool A = inputs[0] ;
    bool B = inputs[1] ;
    bool C = inputs[2] ;
    bool D = inputs[3] ;

    return ( ( A || B ) &&
           ( (!B) || (!C) ) ) ||
           ( A && D ) ;
}

bool boolFunc2( const vector<bool> &inputs ){
    bool x = inputs[0] ;
    bool y = inputs[1] ;
    bool z = inputs[2] ;

    return ( x && (!y) ) ||
           ( (!y) && z ) ||
           ( x && z ) ||
           ( (!x) && y && (!z) ) ;
}

bool boolFunc3( const vector<bool> &inputs ){
    bool A = inputs[0] ;
    bool B = inputs[1] ;
    bool C = inputs[2] ;
    bool D = inputs[3] ;
    bool E = inputs[4] ;

    return ( ( ( C && !(A||B) ) ||
             ( !( ( (C||D) || !E ) && A ) &&
             ( ( ( (!D||C) && A ) || !C ) || E ) && C ) ) &&
           !A ) || E ;
}

bool boolFunc4( const vector<bool> &inputs ){
    bool w = inputs[0] ;
    bool x = inputs[1] ;
    bool y = inputs[2] ;
    bool z = inputs[3] ;

    return ( (!w) && (!x) && (!y) ) ||
           ( (!w) && (!x) && y && (!z) ) ||
           ( (!x) && (!y) && z ) ||
           ( x && y && z ) ||
           ( (!y) && (!z) ) ;
}

bool boolFunc5( const vector<bool> &inputs ){
    bool A = inputs[0] ;
    bool B = inputs[1] ;
    bool C = inputs[2] ;
    bool D = inputs[3] ;

    return ( ( A || ( !A && C ) ) && B ) || ( B && C && !D ) ;
}

/* 
1. str.find("+") 
2. str.find("*")
3. str.find("'")
4. str.find("()")
*/

int main(void){
    int variablesNum ;
    cin >> variablesNum ;
    Generator truthtable( variablesNum , boolFunc3 ) ;

    truthtable.print() ;
    return EXIT_SUCCESS ;
}

/* 
(w+x+y+z) * wyz ;
w'x'y' + w'x'yz' + x'y'z + xyz + y'z'
define "+" = operator(||)
define "*" = operator(&&)
define "'" = operator(!)

order of boolean operations:
    parenthesis -> not -> and -> or
*/