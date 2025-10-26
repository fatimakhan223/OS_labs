#include <stdio.h>
#include <pthread.h>
int deans_list = 0;
pthread_mutex_t lock; //mutex to protect shared variable
typedef struct{
    int student_id;
    char name[50];
    float gpa;
} Student;

void* students_record(void* args){
     Student *data = (Student*)args;

     printf("Student ID: %d\n", data->student_id);
     printf("Name: %s\n", data->name);
     printf("GPA: %.2f\n", data->gpa);

     //check Deans's List eligibility
     if(data->gpa >= 3.5){
        printf("%s on the Dean's list!\n", data->name);
        pthread_mutex_lock(&lock);
        deans_list++;
        pthread_mutex_unlock(&lock);
     }
     else{
        printf("%s did not on the Dean's list.\n", data->name);

        printf("\n");
        return NULL;
     }
}
int main(){
    pthread_t thread_id[3];
     Student student[3] = {
        {101, "Fatima",3.6},
        {102, "Farah", 3.7},
        {103, "Eman",3.7}
    };
    pthread_mutex_init(&lock,NULL);     //initialize mutex
   
    for(int i = 0; i < 3; i++){
        pthread_create(&thread_id[i], NULL, students_record, &student[i]);
    }

    for(int i = 0; i < 3; i++){
        pthread_join(thread_id[i], NULL);
    }
    pthread_mutex_destroy(&lock);       //destroy mutex

    return 0;  
}