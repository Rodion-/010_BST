#include <iostream>
#include <memory>
#include <vector>

#include "bst.h"

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
/*

            */
             /*

            */


            bst.add( std::make_pair ( 6 , 6 ) );
            bst.add( std::make_pair ( 5 , 5 ) );
            bst.add( std::make_pair ( 7 , 7 ) );
            bst.add( std::make_pair ( 4 , 4 ) );
            bst.add( std::make_pair ( 8 , 8 ) );
            bst.add( std::make_pair ( 3 , 3 ) );
            bst.add( std::make_pair ( 9 , 9 ) );
            bst.add( std::make_pair ( 1 , 1 ) );
            bst.add( std::make_pair ( 2 , 2 ) );

            std::cout<<" make BST " << std::endl;

            for( int i = 0; i < 10; i++ )
            {
                int data = bst.get( i );

                if( data >= 0 )
                std::cout<<" data : " << data << std::endl;
            }

            std::cout<<" delete node 5 " << std::endl;

            bst.del( 5 );

            for( int i = 0; i < 10; i++ )
            {
                int data = bst.get( i );

                if( data >= 0 )
                std::cout<<" data : " << data << std::endl;
            }


		}
		#endif
		
        #define EXP1 1
		#if EXP1
        {
            BST bst;

            for( int i = 10; i > 0; i-- )
            {
                bst.add( std::make_pair ( i , i ) );
            }

            std::cout<<" make BST " << std::endl;

            for( int i = 0; i < 10; i++ )
            {
                int data = bst.get( i );

                if( data >= 0 )
                std::cout<<" data : " << data << std::endl;
            }

            std::cout<<" delete node 5 " << std::endl;

            bst.del( 5 );

            for( int i = 0; i < 10; i++ )
            {
                int data = bst.get( i );

                if( data >= 0 )
                std::cout<<" data : " << data << std::endl;
            }
		}
		#endif

        #define EXP2 1
        #if EXP2
        {
            BST bst;

            for( int i = 0; i < 10; i++ )
            {
                bst.add( std::make_pair ( i , i ) );
            }

            std::cout<<" make BST " << std::endl;

            for( int i = 0; i < 10; i++ )
            {
                int data = bst.get( i );

                if( data >= 0 )
                std::cout<<" data : " << data << std::endl;
            }

            std::cout<<" delete node 5 " << std::endl;

            bst.del( 5 );

            for( int i = 0; i < 10; i++ )
            {
                int data = bst.get( i );

                if( data >= 0 )
                std::cout<<" data : " << data << std::endl;
            }

        }
        #endif
		
	}
	catch( ... )
	{
		std::cout<<"error"<<std::endl;
	}
	
	

	return 0;
}






