#ifndef _BUFFER_H_DEFINED_
#define _BUFFER_H_DEFINED_
#include <semaphore.h>
#include <stdbool.h>

typedef int buffer_item;
#define BUFFER_SIZE 5

// Initialize buffer  
buffer_item buffer[BUFFER_SIZE];

// Initialize mutual exclusion object "mutex"
    sem_t mutex;             // define semaphore object
    sem_t empty;
    sem_t full;

bool buffer_insert_item( buffer_item item )
{
    printf("%d", BUFFER_SIZE);
}

bool buffer_remove_item( buffer_item *item );

void initializationFunction()
{

    sem_init( &empty, 0, BUFFER_SIZE );   // Counts empty cells in buffer 
    sem_init( &full, 0, 0);     // Counts filled cells in buffer
    sem_init (&mutex, 0, 1);    // A binary semaphore

    // Initialize all elements of buffer to 0
    for (int i=0; i<BUFFER_SIZE; i++)
    {
        buffer[i] = 0;
    }
}





#endif // _BUFFER_H_DEFINED_


/*
#ifndef _BUFFER_H_DEFINED_
#define _BUFFER_H_DEFINED_

#include <semaphore.h>

using namespace std;

class Buffer {
    public:
        bool buffer_insert_item( buffer_item item );

        bool buffer_remove_item( buffer_item *item );

        buffer();
    
    private:
        typedef int buffer_item;
        
        #define BUFFER_SIZE 5

        // Initialize mutual exclusion object "mutex"
        sem_t mutex;

};

#endif // _BUFFER_H_DEFINED_

*/
/* 

buffer :: buffer (void)
{
// create the semaphore 
sem_init( &mutex, 0, 1 );   

// Initialize the "empty" and "full" semaphores



// acquire the semaphore 
sem_wait( &mutex );

// CRITICAL SECTION 

// release the semaphore 
sem_post( &mutex );
}

*/


