#include <iostream>
#include <memory>
#include <vector>

class ISort
{
	public:
	
	virtual void run ( int* _data , int _size ) = 0;
	
	virtual ~ISort() {};
};


class TesterArray 
{
	std::unique_ptr< ISort > itests;
	int size = 0;
	int* data = nullptr;
	public:	
	
	TesterArray( std::unique_ptr< ISort > _itests , int* _data , int _size ) : itests( std::move( _itests ) ) , data(_data ) , size( _size ) {}
	~TesterArray(){}
	
	void RunTests( void )
	{
		itests->run( data , size );			
	}
};


struct TestData
{
	int elements;
	double time;
};

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
	
	BST* get_this ( void )
	{
		return this;
	}
	
	void add ( std::pair<int , int > data )
	{
		if( key == -1 ) 
		{
			key = data.first;
			value = data.second;
			std::cout<<" add key : " << data.first << " value " << data.second << std::endl;
		}
		else
		{
			if( data.first < key )
			{
				// go to the left
				
				std::cout<<" create left " << std::endl;
				
				if( left == nullptr ) left = new BST;
				
                left->set_head( this );
				left->add( data );
			}
			else
			{
				// go to the rigth
				
				std::cout<<" create right " << std::endl;
				
				if( right == nullptr ) right = new BST;
				
                right->set_head( this );
				right->add( data );
			}
		}
	}
	int get ( int key_ )
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
	
	BST* get_node ( int key_ )
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

    void set_head( BST* b )
    {
        head = b;
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
	
	int get_key( void )
	{
		return key;
	}
	
	int get_value( void )
	{
		return value;
	}
	
	void set_left ( BST* l ){ left = l; }
	void set_right ( BST* r ) { right = r; }
	
	BST* get_left_r ( BST* node )
	{		
        if( node->get_left() == 0 ) return node;
		
		node = this;
		
		get_left_r( node );
		
	}
	
	void del ( int key_ )
	{
		BST* node_to_del = get_node( key_ );
        BST* node_prev = node_to_del->get_head();
		
		if( node_to_del == 0 ) return;

			
		if( node_to_del->get_right() != nullptr )	
		{
			BST* r = node_to_del->get_right();
			
			BST* l = r->get_left();
			
			if( l == nullptr )
			{
				std::cout<<" l = 0  "<<std::endl;
				
                node_prev->set_right( node_to_del->get_right() );
				
                r->set_head( node_prev->get_head() );

				return;
			}
			else
            {
                // go to the last left node
                BST* last_left = nullptr;

                std::cout<<" while(get_left_r( l ) )  "<<l->get_value()<<std::endl;

                while( l->get_left() != nullptr )
                {
                    l = get_left_r( l );
                    std::cout<<" while(get_left_r( l ) )  "<<l->get_value()<<std::endl;
                }

                last_left = l;

                std::cout<<" node_prev key : " << node_prev->get_key() << " value : " << node_prev->get_value() << std::endl;

                last_left->set_head( node_prev->get_head() );
                last_left->set_right( node_prev->get_right() );
                last_left->set_left( node_prev->get_left() );

                node_prev->set_right( last_left );

                BST* next_node = node_to_del->get_right();

                std::cout<<" next_node key : " << next_node->get_key() << " value : " << next_node->get_value() << std::endl;

                next_node->set_head( last_left );
                //next_node->set_left( last_left->get_left() );

                std::cout<<" l value  "<<last_left->get_value()<<std::endl;
			}			
		}
		else
        {
            if( node_to_del->get_left() != nullptr )
            {
                BST* next_l = node_to_del->get_left();
                 std::cout<<" +++++++++++++++++> node_to_del->get_left() != nullptr "<< std::endl;
                if( next_l != nullptr )
                {
                    node_prev->set_left( node_to_del->get_left() );

                     next_l->set_head( node_prev->get_head() );
                }
                else
                {
                    // go to the last left node
                    std::cout<<" l value  "<< next_l->get_value()<<std::endl;
                }
            }
		}
		
		
	
	}
};


int main ( int argc , char** argv )
{
	std::cout<<"algo10"<<std::endl;
		
	try
	{					
	
		std::vector<TestData> SSort(0);
		std::vector<TestData> HSort(0);
		

		
		#define EXP0 1
		#if EXP0
		{
			
			BST bst;
			
            for( int i = 10; i > 0; i-- )
			{	
				bst.add( std::make_pair ( i , i ) );
			}
			
			for( int i = 0; i < 10; i++ )
			{
				int data = bst.get( i );
				
				if( data >= 0 )
				std::cout<<" data : " << data << std::endl;
			}
            ///*
			bst.del( 4 );
            std::cout<<" ------> bst.del( 4 ) " << std::endl;

            for( int i = 0; i < 10; i++ )
			{
				int data = bst.get( i );
			
                if( data >= 0 )
				std::cout<<" data : " << data << std::endl;
			}

            bst.del( 7 );
            std::cout<<" ------> bst.del( 7 ) " << std::endl;

            for( int i = 0; i < 10; i++ )
            {
                int data = bst.get( i );

                if( data  >= 0)
                std::cout<<" data : " << data << std::endl;
            }

			
		}
		#endif
		
        #define EXP1 1
		#if EXP1
		{           

		}
		#endif

        #define EXP2 1
        #if EXP2
        {

        }
        #endif
		
	}
	catch( ... )
	{
		std::cout<<"error"<<std::endl;
	}
	
	

	return 0;
}






