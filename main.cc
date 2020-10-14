
//-----------------------------------------------------------------------------
#include <iostream>
#include "ring.hh"


//-----------------------------------------------------------------------------
using namespace std;


//-----------------------------------------------------------------------------
int main( int, char*[] ) {

  mad::ring ring( { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } } );
  cout << "ring" << endl << ring << endl << endl;

  mad::ring circle( ring );
  cout << endl << "circle" << endl << circle << endl << endl;


  return 0;  // OK

};  // end main
