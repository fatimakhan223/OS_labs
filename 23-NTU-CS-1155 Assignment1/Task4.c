#include <stdio.h>
#include <pthread.h>
// Reg no: 23-NTU-CS-1155 Name: Fatima Waseem
void* print_factorial(void* arg){
    int num = *(int*)arg;
    int fact = 1;
    for( int i = 1; i <= num; i++){
        fact = fact*i;
    }
    printf("Thread received %d number and its factorial is: %d.", num, fact);
    return NULL;
}
int main(){
    pthread_t thread_id;
    int number;
    printf("Enter the number: \n");
    scanf("%d", &number);
    //thread create
    pthread_create(&thread_id, NULL, print_factorial, &number);
    //Waiting for the thread finish
    pthread_join(thread_id, NULL);
    return 0;
}