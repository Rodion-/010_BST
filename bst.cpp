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
    if( key_ == key )
    {
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
    }
    else
    {
        if( data.first < key )
        {
            // go to the left

            if( left == nullptr ) left = new BST;

            left->set_head( this );
            left->add( data );
        }
        else
        {
            if( data.first > key )
            {
                // go to the rigth

                if( right == nullptr ) right = new BST;

                right->set_head( this );
                right->add( data );
            }
            else
            {
                if( data.first == key ) return;
            }
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

        if( right == nullptr )
        {
            return -1;
        }

        right->get( key_ );
    }
}

void BST::del ( int key_ )
{
    BST* node_to_del = get_node( key_ );

    if( node_to_del == nullptr )
    {
        return;
    }



    if( ( node_to_del->get_right() == nullptr ) && ( node_to_del->get_left() == nullptr ) )
    {
        //  this is last node

        BST* head = node_to_del->get_head();

        if( head->get_left() == node_to_del )
        {
            head->set_left( nullptr );
        }
        else
        {
            if( head->get_right() == node_to_del )
            {
                head->set_right( nullptr );
            }
            else
            {
                std::cout<< " error del last node !!! " << std::endl;
            }
        }
        node_to_del->free_mem();

        return;
    }

    if( ( node_to_del->get_right() != nullptr ) && ( node_to_del->get_left() == nullptr ) )
    {
        //std::cout<<" this is rigth three " << std::endl;

        BST* head = node_to_del->get_head();

        if( head == nullptr ) return;

        if( head->get_left() == node_to_del )
        {
            head->set_left( node_to_del->get_right() );
        }
        else
        {
            if( head->get_right() == node_to_del )
            {
                head->set_right( node_to_del->get_right() );
            }
            else
            {
                std::cout<< " error del last node !!! " << std::endl;
            }
        }

        node_to_del->get_right()->set_head( head );

        node_to_del->free_mem();

        return;
    }
    if( ( node_to_del->get_right() == nullptr ) && ( node_to_del->get_left() != nullptr ) )
    {
        //std::cout<<" this is left three " << std::endl;

        BST* head = node_to_del->get_head();

        if( head->get_left() == node_to_del )
        {
            head->set_left( node_to_del->get_left() );
        }
        else
        {
            if( head->get_right() == node_to_del )
            {
                head->set_right( node_to_del->get_left() );
            }
            else
            {
                std::cout<< " error del last node !!! " << std::endl;
            }
        }

        node_to_del->get_left()->set_head( head );


        node_to_del->free_mem();

        return;
    }

    if( ( node_to_del->get_right() != nullptr ) && ( node_to_del->get_left() != nullptr ) )
    {
       // std::cout<<" this is left - right three " << std::endl;

        BST* right_node = node_to_del->get_right();

        BST* last_left_node = right_node->dfs_l( right_node );

        BST* head = node_to_del->get_head();

        if( head == nullptr ) return;

        if( last_left_node != right_node )
        {
             //  1  ,   2
            if( last_left_node->get_right() )
            {
                last_left_node->get_right()->set_head( last_left_node->get_head() );
                last_left_node->get_head()->set_left( last_left_node->get_right() );
            }
            else
            {
                last_left_node->get_head()->set_left( nullptr );
            }

            //  3   ,   4
            last_left_node->set_head( head );

            if( head->get_left() == node_to_del )
            {
                head->set_left( last_left_node );
            }
            else
            {
                if( head->get_right() == node_to_del )
                {
                    head->set_right( last_left_node );
                }
                else
                {
                    std::cout<< " error del last node !!! " << std::endl;
                }
            }

            //  5   ,   6
            last_left_node->set_right( right_node );

            right_node->set_head( last_left_node );

            //  7   ,   8
            last_left_node->set_left( node_to_del->get_left() );

            node_to_del->get_left()->set_head( last_left_node );
        }
        else
        {
            //  1
            right_node->set_head( head );

            //  2
            if( head->get_left() == node_to_del )
            {
                head->set_left( right_node );
            }
            else
            {
                if( head->get_right() == node_to_del )
                {
                    head->set_right( right_node );
                }
                else
                {
                    std::cout<< " error del last node !!! " << std::endl;
                }
            }

            //  3   ,   4
            if( node_to_del->get_left() )
            {
                right_node->set_left( node_to_del->get_left() );

                node_to_del->get_left()->set_head( right_node );
            }
            else
            {
                right_node->set_left( nullptr );
            }

        }
        node_to_del->free_mem();

        return;

    }
}
