#include "truthtab_gen.h"

bool boolFunc( const vector<bool> &inputs ){
    bool w = inputs[0] ;
    bool x = inputs[1] ;
    bool y = inputs[2] ;
    bool z = inputs[3] ;

    return ( (!w) && z && ( (!x) || y ) ) ||
		   ( (!y) && (!z) ) ||
		   ( (!x) && (!y) ) ||
		   ( x && y && z ) ;
}

bool boolFunc2( const vector<bool> &inputs ){
	bool w = inputs[0] ;
	bool x = inputs[1] ;
	bool y = inputs[2] ;
	bool z = inputs[3] ;
	
	return ( x && y && z ) ||
		   ( (!y) && (!z) ) ||
		   ( ( (!w) || z ) && (!x) && (!y) ) ;
}

int main(void){
    int variablesNum ;
    cin >> variablesNum ;
    Generator truthtable( variablesNum , boolFunc2 ) ;

    truthtable.print() ;
    return EXIT_SUCCESS ;
}

/* 
w'x'y' + w'x'yz' + x'y'z + xyz + y'z'
y'z' + x'y' + w'x'z + w'yz + xyz
*/