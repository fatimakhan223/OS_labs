#include <stdio.h>
 #include <pthread.h>
 
 int counter = 0; 
 void* increment(void* arg) {
 for (int i = 0; i < 100000; i++) {
 counter++; // Not thread-safe
 }
 return NULL;
 }
 int main() {

    pthread_t thread[3];
    for(int i = 0; i< 3; i++){
        pthread_create(&thread[i], NULL, increment, NULL);
    }
    
    for(int i = 0; i<3; i++){
        pthread_join(thread[i], NULL);
    }
    printf("value:%d\n",counter);
 return 0;
 }