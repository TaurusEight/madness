
#include <iostream>
#include "ring.hh"

using namespace std;
using namespace mad;



//-----------------------------------------------------------------------------
ring::ring( ) : head( nullptr ) { };


//-----------------------------------------------------------------------------
ring::ring( list_t IL ) : head( nullptr ) {

  head = build( IL );

};  // end constructor


// copy constructor
//-----------------------------------------------------------------------------
ring::ring( const ring& R ) : head( nullptr ) {

  copy( R );

};  // end copy constructor


// move constructor
//-----------------------------------------------------------------------------
ring::ring( ring&& R ) : head( nullptr ) {

  move( R );

};  // end move constructor

//-----------------------------------------------------------------------------
ring::~ring( ) {

  nuke( head );

};  // end destructor


//-----------------------------------------------------------------------------
void ring::move( ring& R ) {

  head = R.head;
  R.head = nullptr;

};  // end move

//-----------------------------------------------------------------------------
void ring::copy( const ring& R ) {

  if ( R.head == nullptr ) return;  // nothing to do
  node* r_current = R.head;
  node* row = nullptr;
  node* prev = nullptr;

  do {
    row = build_list( r_current );
    if ( head == nullptr ) head = row;
    if ( prev != nullptr ) link_row( prev, row );
     prev = row;
    r_current = r_current->next_col;
  } while( *r_current != *(R.head) );

};  // end copy


// copy constructor
//-----------------------------------------------------------------------------
ring& ring::operator=( const ring& R ) {

  nuke( head );
  copy( R );
  return *this;

};  // end operator=


// move constructor
//-----------------------------------------------------------------------------
ring& ring::operator=( ring&& R ) {

  nuke( head );
  move( R );
  return *this;

};  // end operator=

//-----------------------------------------------------------------------------
node* ring::build_list( node* N ) const {

  if ( N == nullptr ) return nullptr;  // nothing to do

  node* target = N;
  node* last = nullptr;
  node* current = nullptr;
  node* start = nullptr;

  do {
    current = new node( target->value );
    if ( start == nullptr ) start = current;
    if ( last != nullptr ) {
      current->next_row = last->next_row;
      last->next_row = current;
    };
    last = current;  // end if / else
    target = target->next_row;
  } while( *target != *N );

  return start;

};  // end build_list

//-----------------------------------------------------------------------------
node* ring::build_list( initializer_list< int > L ) const {

  node* start = nullptr;
  node* current = nullptr;
  node* last = nullptr;

  for ( auto& value : L ) {
    current = new node( value );
    if ( start != nullptr ) {
      do { last = start->next_row; } while ( *last->next_row != *start );
      current->next_row = last->next_row;
      last->next_row = current;
    } else start = current;
  };  // end for L

  return start;

};  // end list


//-----------------------------------------------------------------------------
void ring::link_row( node* prev, node* current ) const {

  node* iter = prev;
  node* target = current;

  do {
    target->next_col = iter->next_col;
    iter->next_col = target;
    iter = iter->next_row;
    target = target->next_row;
  } while ( *iter != *prev );

};  // end link_row


//-----------------------------------------------------------------------------
node* ring::build( list_t IL ) const {

  node* result = nullptr;
  node* prev = nullptr;
  node* current = nullptr;


  for ( auto& row_list : IL ) {
    current = build_list( row_list );
    if ( result == nullptr ) result = current;
    if ( prev != nullptr ) link_row( prev, current );
    prev = current;
  };  // end row

  return result;

};  // end build


//-----------------------------------------------------------------------------
void ring::nuke_row( node* start, node* current ) {

  if ( *start != *current->next_row ) nuke_row( start, current->next_row );
  delete current;

};  // end nuke_row



//-----------------------------------------------------------------------------
void ring::nuke( node* current ) {

  if ( head == nullptr ) return;

  if ( *head != *current->next_col ) nuke( current->next_col );
  nuke_row( current, current );

};  // end nuke


//-----------------------------------------------------------------------------
void output_row( ostream& out, node* start ) {

  node* current = start;
  do {
    out << current->value << ' ';
    current = current->next_row;
  } while( *current != *start );

};  // end output_row


//-----------------------------------------------------------------------------
ostream& mad::operator<<( ostream& out, const ring& R ) {

  if ( R.head == nullptr ) {
    out << "{ }";
    return out;
  };  // end if nullptr

  node* current = R.head;
  do {
    out << "{ ";
    output_row( out, current );
    current = current->next_col;
    out << '}' << endl;
  } while( *current != *(R.head) );

  return out;

};  // end operator<< ring
