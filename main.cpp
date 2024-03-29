#include <iostream>
#include <memory>
#include <vector>

#include <chrono>

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
		
        double left_time [ 10 ] = { 0 };

        #define EXP3 1
        #if EXP3
        {
            BST bst;

            auto start = std::chrono::system_clock::now();

            //  1   make BST of 1000 random nodes
            for( int i = 0; i < 1000; i++ )
            {
                int32_t t = std::rand()%10000;

                std::cout<<" t : " << t << std::endl;

                bst.add( std::make_pair ( t , t ) );
            }

            //  2   get 100 random nodes
            for( uint32_t i = 0; i < 100; i++ )
            {

                int32_t t = std::rand()%10000;

                BST* b = bst.get_node( t );

                if( b != nullptr )
                std::cout << b->get_key() << " " << b->get_value() << std::endl;

            }

            //  3   remove 100 random nodes
            for( uint32_t i = 0; i < 100; i++ )
            {

                int32_t t = std::rand()%10000;

                if( bst.get_node( t ) == 0 )
                {
                    continue;
                }
                else
                {
                    std::cout<<" finde : " << t << std::endl;
                    bst.del( t );
                }
            }
            //  4   output all nodes
            for( int i = 0; i < 1000; i++ )
            {
                int data = 0;

                data = bst.get( i );

                if( data >= 0 )
                std::cout<<" data after del : " << data << std::endl;
            }

            auto end = std::chrono::system_clock::now();
            std::chrono::duration<double> diff = end - start;

            left_time[ 0 ] = diff.count();
        }
        #endif

        #define EXP4 1
        #if EXP4
        {
            BST bst;

            auto start = std::chrono::system_clock::now();

            //  1   make BST of 1000 linear increase nodes
            for( int i = 0; i < 1000; i++ )
            {
                bst.add( std::make_pair ( i , i ) );
            }

            //  2   get 100 random nodes
            for( uint32_t i = 0; i < 100; i++ )
            {

                int32_t t = std::rand()%1000;

                BST* b = bst.get_node( t );

                if( b != nullptr )
                std::cout << b->get_key() << " " << b->get_value() << std::endl;

            }

            //  3   remove 100 random nodes
            for( uint32_t i = 0; i < 100; i++ )
            {

                int32_t t = std::rand()%1000;

                if( bst.get_node( t ) == 0 )
                {
                    continue;
                }
                else
                {
                    std::cout<<" finde : " << t << std::endl;
                    bst.del( t );
                }
            }
            //  4   output all nodes
            for( int i = 0; i < 1000; i++ )
            {
                int data = 0;

                data = bst.get( i );

                if( data >= 0 )
                std::cout<<" data after del : " << data << std::endl;
            }

            auto end = std::chrono::system_clock::now();
            std::chrono::duration<double> diff = end - start;

             left_time[ 1 ] = diff.count();
        }
        #endif

        std::cout<< " ----------------------- "<< std::endl;
        std::cout<< " |  BST     | TIME LEFT | "<< std::endl;
        std::cout<< " ----------------------- "<< std::endl;
        std::cout<< " | random   | " << left_time[ 0 ] << "|" << std::endl;
        std::cout<< " | linear   | " << left_time[ 1 ] << "|" << std::endl;
        std::cout<< " ----------------------- "<< std::endl;


        std::cout<<" end of the programm " << std::endl;
	}
	catch( ... )
	{
		std::cout<<"error"<<std::endl;
	}
	
	

	return 0;
}






