#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

sem_t manager;
void* download_funtion(void* arg){
    int id = *(int*)arg;        //Cast first, dereference second

    printf("Downloads %d: waiting for manager slot\n", id);
    sem_wait(&manager);

    int time = (rand() % 5) + 1;
    printf("Download %d: Started (time = %d seconds)\n",id ,time);
    sleep(time);
    printf("Download %d: Finished\n",id);

    sem_post(&manager);     //release slot;
    return NULL;

}

int main(){
    int N = 3;  //maximum simultaneous downloads
    int total_downloads = 8;
    sem_init(&manager, 0, N); //Initialize semaphore with number of n capacity
    pthread_t downloads[total_downloads];
    int id[total_downloads];

    for(int i = 0; i < total_downloads; i++){
        id[i] = i+1;
        pthread_create(&downloads[i], NULL, download_funtion, &id[i]);
       
    }

    for(int i = 0; i < total_downloads; i++){
        id[i] = i+1;
        pthread_join(downloads[i],NULL);
    }

    sem_destroy(&manager);
    return 0;
}