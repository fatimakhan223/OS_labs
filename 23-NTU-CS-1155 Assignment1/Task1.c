#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>     // for rand() and srand()
#include <time.h> // for time()

#define NUM_THREADS 5

// Reg no: 23-NTU-CS-1155 Name: Fatima Waseem
void *thread_function(void *args){
    int thread_num = *(int *)args;      //get thread number (1,2,3, ...)
    pthread_t tid = pthread_self();     // thread ID

    printf("Thread %d started. Thread ID: %lu\n", thread_num, tid);

    int sleep_time  = (rand() % 3) + 1;        // random number between 1 and 3
    sleep(sleep_time);

    printf("Thread %d (ID: %lu) completed after %d seconds.\n", thread_num, tid, sleep_time);

    return NULL;
}

int main(){
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    srand(time(NULL));      //seed random number generator

    for(int i = 0; i < NUM_THREADS; i++){
        thread_args[i] = i + 1; // thread number 1-5
        pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);

    }

    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished execution. \n");
    return 0;
}