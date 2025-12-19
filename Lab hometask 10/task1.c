#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t rooms;

void* guest_function(void* arg){
    int id = *(int*)arg;

    printf("Guest %d: Waiting for room...\n", id);

    sem_wait(&rooms);       // Try to take a room (wait if none available)


// Critical Section (guest gets a room)
    printf("Guest %d: Checked in! Got a room \n",id);
    sleep(2);       //staying in the room

    printf("Guest %d: Leaving room...\n", id);

    sem_post(&rooms);   // Release the room
    return NULL;
}
int main(){
    int N = 3;      //Number of rooms
    int total_guests = 7;   //Total people trying to get a room
    sem_init(&rooms, 0, N);      // Initialize rooms semaphore with N rooms
    pthread_t  guests[total_guests];
    int ids[total_guests];

    for(int i = 0 ; i < total_guests; i++){
        ids[i] = i + 1;
        pthread_create(&guests[i], NULL, guest_function,&ids[i]);
        sleep(1);
    }

    for(int i = 0 ; i < total_guests; i++){
        pthread_join(guests[i],NULL);
    }

    sem_destroy(&rooms);
    printf("All guests processd\n");

    return 0;


}