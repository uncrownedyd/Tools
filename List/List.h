#include <iostream>

template <typename Object>

class List
{
public:
    List();

    List( const List & rhs);

    ~List();

    const List & operator= ( const List &rhs );


public:
    class const_iterator;

    class iterator : public const_iterator;    

private:
    struct  Node;

    int     theSize;
    Node    *head;
    Node    *tail;

    void    init();
};

struct Node 
{
    Object  data;
    Node    *prev;
    Node    *next;

    Node ( const Object &obj = Object(), Node *p = NULL, Node *n = NULL )
        : data( d ), prev( p ), next( n ) { }
};
