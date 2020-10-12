#ifndef __NODE_HH__
#define __NODE_HH__


//-----------------------------------------------------------------------------
#include <stdlib.h>

//-----------------------------------------------------------------------------
namespace mad {

  // data object
  struct node {

    node( int );// : value( 0 ), next_row( nullptr ), next_col( nullptr ) {};
    node();
    ~node();
    bool operator==( const node& ) const;
    bool operator!=( const node& ) const;
    int value;
    node* next_row;
    node* next_col;

    //    void* operator new( size_t );
    //    void operator delete( void* ptr );

    //    static int count;

  };  // end node

  //---------------------------------------------------------------------------
  std::ostream& operator<<( std::ostream&, const node* );

};  // end NM mad

#endif  // __NODE_HH__
