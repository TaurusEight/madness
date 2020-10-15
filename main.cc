
//-----------------------------------------------------------------------------
#include <iostream>
#include "ring.hh"


//-----------------------------------------------------------------------------
using namespace std;


//-----------------------------------------------------------------------------
int main( int, char*[] ) {

  mad::ring ring( { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } } );
  cout << "ring" << endl << ring << endl << endl;

  cout << "Test copy constructor" << endl;
  mad::ring circle( ring );
  cout << endl << "circle" << endl << circle << endl << endl;

  cout << "Test assignment operator" << endl;
  mad::ring square;
  cout << endl << "square before: " << endl;
  cout << square << endl << endl;
  square = circle;
  cout << endl << "square after: " << endl << square << endl << endl;

  cout << "Test move constructor" << endl;
  mad::ring triangle( move( square ) );
  cout << "triangle: " << endl << triangle << endl << endl;
  cout << endl << "square after move: " << endl << square << endl << endl;

  cout << "Test move operator" << endl;
  mad::ring blob;
  cout << "blob before: " << endl << blob << endl << endl;
  blob = move( triangle );
  cout << "blob after move:" << endl << blob << endl << endl;
  cout << "triangle after move:" << endl << triangle << endl << endl;

  return 0;  // OK

};  // end main
