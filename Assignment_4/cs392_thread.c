
//“I pledge my honor that I have abided by the Stevens Honor System.” - Brereton Conway

#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_THREADS 3


//global variables
int item1_counter = 0;
int item2_counter = 0;
int item3_counter = 0;

//mutex variables
pthread_mutex_t lock1;
pthread_mutex_t lock2;
pthread_mutex_t lock3;

//function to be run by threads
void* cs392_thread_run(void* arg);

int main(int argc, char* argv[]) {

    //check for correct amount of arguements
    if(argc != 4){
        printf("please enter 3 file paths/names when running this program\n");
        printf("quiting...\n");
        return 0;
    }

    //init mutex vars, checking for errors
    int check1 = pthread_mutex_init(&lock1, NULL);
    int check2 = pthread_mutex_init(&lock2, NULL);
    int check3 = pthread_mutex_init(&lock3, NULL);
    if((check1 != 0) || (check2 != 0) || (check3 != 0)){
        printf("mutex init error");
        return -1;
    }

    //create array of pthread_t vars them iteratively create threads, passing argv's as arguements
    pid_t tid;
    pthread_t* tids = (pthread_t*)malloc(NUMBER_OF_THREADS * sizeof(pthread_t));
    int t;
    for(int i = 0; i < NUMBER_OF_THREADS; i++){
        t = pthread_create(tids + i, NULL, cs392_thread_run, (void*)argv[i + 1]);
        if(t != 0){
            perror("pthread_create");
            return -1;
        }
    }

    //join threads
    for(int i = 0; i < NUMBER_OF_THREADS; i++){
        pthread_join(tids[i], (void**)&tid);
    }
    //destroy mutex vars
    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);
    pthread_mutex_destroy(&lock3);

    //what is the answer
    printf("The final value of item1_counter, item2_counter, and item3_counter are %d, %d, and %d \n", item1_counter, item2_counter, item3_counter);
    return 0;
}


void* cs392_thread_run(void* arg){
    //open file and get string line by line, checking if it equals prespecified token, and adjusting global var accordingly
    size_t len = 50;
    char *line = NULL;
    FILE* file_ptr = fopen((char*)arg, "r");
    if(file_ptr == NULL){
        perror("error opening file");
    }
    while( getline(&line, &len, file_ptr) != -1){
        if(strcmp(line, "+item1\n\0") == 0){
            pthread_mutex_lock(&lock1);
            item1_counter++;
            pthread_mutex_unlock(&lock1);
        }
        else if(strcmp(line, "-item1\n\0") == 0){
            pthread_mutex_lock(&lock1);
            item1_counter--;
            pthread_mutex_unlock(&lock1);
        }
        else if(strcmp(line, "+item2\n\0") == 0){
            pthread_mutex_lock(&lock2);
            item2_counter++;
            pthread_mutex_unlock(&lock2);
        }
        else if(strcmp(line, "-item2\n\0") == 0){
            pthread_mutex_lock(&lock2);
            item2_counter--;
            pthread_mutex_unlock(&lock2);
        }
        else if(strcmp(line, "+item3\n\0") == 0){
            pthread_mutex_lock(&lock3);
            item3_counter++;
            pthread_mutex_unlock(&lock3);
        }
        else if(strcmp(line, "-item3\n\0") == 0){
            pthread_mutex_lock(&lock3);
            item3_counter--;
            pthread_mutex_unlock(&lock3);
        }

    }
    free(line);
    pthread_exit(NULL);
}
