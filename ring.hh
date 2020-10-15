#ifndef __RING_HH__
#define __RING_HH__

//-----------------------------------------------------------------------------
#include <initializer_list>
#include "node.hh"  // mad::node

//-----------------------------------------------------------------------------
namespace mad {

  using list_t = std::initializer_list< std::initializer_list< int > >;

  //---------------------------------------------------------------------------
  class ring {

  public:

    ring();
    ring( list_t );
    ring( const ring& );  // copy constructor
    ring( ring&& );  // move constructor
    ~ring();

    ring& operator=( const ring& );  // copy assignmnet
    ring& operator=( ring&& );  // move assignment

    friend std::ostream& operator<<( std::ostream&, const ring& );

  protected:

    void move( ring& );
    void copy( const ring& );
    node* build_list( std::initializer_list< int > ) const;
    node* build_list( node* ) const;
    void link_row( node*, node* ) const;
    node* build( list_t ) const;
    void nuke_row( node*, node* );
    void nuke( node* );

  private:

    node* head;

  };  // end ring

  std::ostream& operator<<( std::ostream&, const ring& );

};  // end NS mad


#endif  // __RING_HH__
