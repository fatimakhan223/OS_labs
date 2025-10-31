#include <stdio.h>
#include <pthread.h>
int counter = 0;
pthread_mutex_t lock;
void* increment(void* arg){
    pthread_mutex_lock(&lock);
    for(int i = 0; i<1000; i++){ 
        counter++;
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}
int main(){
    pthread_mutex_init(&lock,NULL);
    pthread_t thread[3];
    
    for(int i= 0; i<3; i++){
        pthread_create(&thread[i],NULL,increment,NULL);
    }
    for(int i= 0; i<3; i++){
        pthread_join(thread[i],NULL);
    }
    
    printf("The counter value is: %d\n",counter);
    pthread_mutex_destroy(&lock);
    return 0;
}