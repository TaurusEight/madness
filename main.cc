
//-----------------------------------------------------------------------------
#include <iostream>
#include "ring.hh"


//-----------------------------------------------------------------------------
using namespace std;


//-----------------------------------------------------------------------------
int main( int, char*[] ) {

  mad::ring one( { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } } );
  cout << "one" << endl << one << endl << endl;

  cout << "Test copy constructor - 'mad::ring circle( one );'" << endl;
  mad::ring circle( one );
  cout << endl << "circle" << endl << circle << endl << endl;

  cout << "Test assignment operator - 'square = circle;'" << endl;
  mad::ring square;
  cout << "square before: " << endl;
  cout << square << endl << endl;
  square = circle;
  cout << endl << "square after: " << endl << square << endl << endl;

  cout << "Test move constructor - 'mad::ring triangle( move( square ) );'" << endl;
  mad::ring triangle( move( square ) );
  cout << "triangle: " << endl << triangle << endl << endl;
  cout << endl << "square after move: " << endl << square << endl << endl;

  cout << "Test move operator - 'blob = move( triangle );'" << endl;
  mad::ring blob;
  cout << "blob before: " << endl << blob << endl << endl;
  blob = move( triangle );
  cout << "blob after move:" << endl << blob << endl << endl;
  cout << "triangle after move:" << endl << triangle << endl << endl;

  return 0;  // OK

};  // end main
