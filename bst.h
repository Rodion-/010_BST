#ifndef BST_H
#define BST_H

#include <iostream>

class BST
{
    int key;
    int value;

    BST* head;
    BST* left;
    BST* right;

    public:

    BST() : key( -1 ) , head( nullptr ) , left( nullptr ) , right( nullptr ) {}
    ~BST(){}

    void print_myself( void )
    {
        std::cout<< " key " << key << " value " << value << std::endl;
    }

    BST* dfs_l ( BST* node );
    BST* dfs_r ( BST* node );

    BST* get_this ( void )
    {
        return this;
    }

    void add ( std::pair<int , int > data );

    int get ( int key_ );

    void del ( int key_ );


    BST* get_node ( int key_ );


    void set_head( BST* b )
    {
        head = b;
    }

    void set_left ( BST* l )
    {
        left = l;
    }
    void set_right ( BST* r )
    {
        right = r;
    }

    BST* get_head( void )
    {
        return head;
    }

    BST* get_right ( void )
    {
        return right;
    }

    BST* get_left ( void )
    {
        return left;
    }

    void set_key( int k )
    {
        key = k;
    }

    void set_value( int v )
    {
        value = v;
    }

    int get_key( void )
    {
        return key;
    }

    int get_value( void )
    {
        return value;
    }

    void free_mem ( void )
    {
        delete this;
    }
};

#endif // BST_H
