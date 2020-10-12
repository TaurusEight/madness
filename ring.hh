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
    ~ring();

    friend std::ostream& operator<<( std::ostream&, const ring& );

  protected:

    node* build_list( std::initializer_list< int > ) const;
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
