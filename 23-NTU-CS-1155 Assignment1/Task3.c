#include <stdio.h>
#include <pthread.h>
// Reg no: 23-NTU-CS-1155 Name: Fatima Waseem
void* print_number(void* arg){
    int num = *(int*)arg;
    int square = num * num;
    int cube = num * num * num;
    printf("Thread received %d and its square is %d and its cube is %d.\n", num, square,cube);
    return NULL;
}
int main(){
    pthread_t thread_id;
    int number;
    printf("Enter the number:\n");
    scanf("%d", &number); 

    //create thread
    pthread_create(&thread_id, NULL, print_number, &number);

    //wait for the thread finish
    pthread_join(thread_id, NULL);
    printf("Main thread done.\n");
    return 0;
}