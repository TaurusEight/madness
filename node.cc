
//-----------------------------------------------------------------------------
#include <iostream>
#include "node.hh"

//-----------------------------------------------------------------------------
using namespace std;
using namespace mad;

//int node::count = 0;

//-----------------------------------------------------------------------------
node::node( int V ) : value( V ), next_row( this ), next_col( this ) {
};  // end constructor


//-----------------------------------------------------------------------------
node::node( ) : node( 0 ) {
};


node::~node() { cout << "node::~node -> " << value << endl; };

//-----------------------------------------------------------------------------
bool node::operator==( const node& N ) const {
  return value == N.value;
};  // end operator==


//-----------------------------------------------------------------------------
bool node::operator!=( const node& N ) const {
  return value != N.value;
};  // end operator!=


//-----------------------------------------------------------------------------
//void* node::operator new( size_t size ) {
//  node::count = node::count + 1;
//  cout << "Current node count is " << node::count << endl;
//  return ::new node();
//}  // end new


//-----------------------------------------------------------------------------
//void node::operator delete( void* ptr ) {
//  node::count = node::count - 1;
//  free( ptr );
//};  // end delete


//-----------------------------------------------------------------------------
ostream& operator<<( ostream& out, const node* ptr ) {
  out << ptr->value;
  return out;
};  // end operator<<
