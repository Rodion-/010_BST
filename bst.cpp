#include "bst.h"

BST* BST :: dfs_l ( BST* node )
{
    if( ( node != nullptr ) && ( node->left == nullptr ) ) return node;

    dfs_l( node->left );
}

BST* BST :: dfs_r ( BST* node )
{
    if( ( node != nullptr ) && ( node->right == nullptr ) ) return node;

    dfs_r( node->right );
}


BST* BST :: get_node ( int key_ )
{
    //BST* node = nullptr;

    if( key_ == key )
    {
        //node = this;

        return this;
    }

    if( key_ < key )
    {
        //	go to the left

        if( left == nullptr ) return 0;

        left->get_node( key_ );
    }
    else
    {
        //	go to the right

        if( right == nullptr ) return 0;

        right->get_node( key_ );
    }
}


void BST::add(std::pair<int, int> data)
{
    if( key == -1 )
    {
        key = data.first;
        value = data.second;
        //std::cout<<" add key : " << data.first << " value " << data.second << std::endl;
    }
    else
    {
        if( data.first < key )
        {
            // go to the left

            //std::cout<<" create left " << std::endl;

            if( left == nullptr ) left = new BST;

            left->set_head( this );
            left->add( data );
        }
        else
        {
            // go to the rigth

            //std::cout<<" create right " << std::endl;

            if( right == nullptr ) right = new BST;

            right->set_head( this );
            right->add( data );
        }
    }
}

int BST :: get ( int key_ )
{
    if( key_ == key ) return value;

    if( key_ < key )
    {
        //	go to the left

        if( left == nullptr )
        {
            return -1;
        }

        left->get( key_ );
    }
    else
    {
        //	go to the right

        if( right == nullptr ) return -1;

        right->get( key_ );
    }
}

void BST::del ( int key_ )
{
    BST* node_to_del = get_node( key_ );

    if( ( node_to_del->get_right() == nullptr ) && ( node_to_del->get_left() == nullptr ) )
    {
        std::cout<<" this is last nod " << std::endl;

        return;
    }

    if( ( node_to_del->get_right() != nullptr ) && ( node_to_del->get_left() == nullptr ) )
    {
        std::cout<<" this is rigth three " << std::endl;

        BST* head = node_to_del->get_head();

        head->set_right( node_to_del->get_right() );

        BST* next = node_to_del->get_right();

        next->set_head( head->get_this() );

        return;
    }

    if( ( node_to_del->get_right() == nullptr ) && ( node_to_del->get_left() != nullptr ) )
    {
        std::cout<<" this is left three " << std::endl;

        BST* head = node_to_del->get_head();

        head->set_left( node_to_del->get_left() );

        BST* next = node_to_del->get_left();

        next->set_head( head->get_this() );

        return;
    }
}
