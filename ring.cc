
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


//-----------------------------------------------------------------------------
ring::~ring( ) {

  cout << "ring::~ring " << ( head == nullptr ? "null" : "not null" ) << endl;

  if ( head == nullptr ) return;
  nuke( head );

};  // end destructor


//-----------------------------------------------------------------------------
node* ring::build_list( initializer_list< int > L ) const {

  node* start = nullptr;
  node* current = nullptr;
  node* last = nullptr;

  for ( auto& value : L ) {
    current = new node( value );
    cout << ' ' << value << ' ';
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
    cout << '{';
    current = build_list( row_list );
    if ( result == nullptr ) result = current;
    if ( prev != nullptr ) link_row( prev, current );
    prev = current;
    cout << '}' << endl;
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
