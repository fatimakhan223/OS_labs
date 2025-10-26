#include <stdio.h>
#include <pthread.h>
// Reg no: 23-NTU-CS-1155 Name: Fatima Waseem
void  *print_name(void* args){
char *name = (char *) args;             //char *name → declares a pointer to char
printf("Hello %s !  Welcome to the world of threads.\n", name);
return NULL;
}

int main(){
  pthread_t thread_id;
  char name[10];
  printf("Enter the name:");
  scanf("%19s", name);

  printf("Main thread: Waiting for greeting.\n");
  
  // thread creating
  pthread_create(&thread_id, NULL, print_name, name);

  // Wait for thread to finish
  pthread_join(thread_id, NULL);
  printf("Main thread: Greeting completed.\n");
  return 0;
}