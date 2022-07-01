#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "buffer.h"
#include <semaphore.h>

int value;

void * generateNumber1(void * s)
{
    int randNo;
    unsigned int seed1 = 0;
    unsigned int seed2 = 0;

// Generate and print a sequence of random numbers.
//for (int i=0; i<2; i++)
  //  { 
    wait(mutex);
    wait(empty);
    sem_getvalue(&full, &value);
    //sem_getvalue(full, getSemValue);
    printf("This is the value: %d", value);
    seed1 = rand();  // Create a random seed, to create random numbers in the function below
    randNo = (int) (rand_r(&seed1) % 200); // % 200 sets range between 200
    printf("I am thread: %d: With number %d\n", pthread_self(), randNo);
    usleep((int) (rand_r(&seed2) % 20));    // Put thread to sleep for random number of time. 
    signal(0, full);
    signal(0, mutex);
    

    //}

   pthread_exit(0); 
   return NULL;
}


    void printBuffer ()
    {
        
    }

int main(int argc, char *argv[]) {

    // Create a terminal-input specified number of threads. 
    int SIZE = atoi(argv[1]);
    pthread_t tid[SIZE];
    pthread_attr_t attr; 
    pthread_attr_init(&attr); 



    // Before rand_r can be used, a seed must be generated. 
    // A. Generate a unique seed
    // 99. Use the time() to generate a unique seed, and add +1 for each subsequent thread
    // 98. Use a thread pid to be the seed. 
    // 97. Seed syntax
    // 97.99. unsigned int seed = 5     // Seed syntax
    //        int rand_no_y = (int) (rand_r(&seed) % 50);   // Generate random numbers 0-50


    // Call all threads to run the function concurrently.  
    /* set the scheduling algorithm to PCS or SCS */ 
   pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM); 
   /* create the threads */
   for (int i = 0; i < SIZE; i++) 
      pthread_create(&tid[i],&attr,generateNumber1,NULL); 
   /* now join on each thread */
   for (int i = 0; i < SIZE; i++)
      pthread_join(tid[i], NULL); 
    
    buffer_insert_item(20);
    initializationFunction();

    

    return 0;

}

