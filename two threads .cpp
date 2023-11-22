//teo threads
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
int sharedData = 5; 
sem_t semaphore;
void* thread1_function(void* arg);
void* thread2_function(void* arg);
int main() {
    sem_init(&semaphore, 0, 1);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread1_function, NULL);
    pthread_create(&thread2, NULL, thread2_function, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    sem_destroy(&semaphore);

    return 0;
}
void* thread1_function(void* arg)
 {
    sem_wait(&semaphore);
    int doubledValue = sharedData * 2;
    printf("Thread 1: Doubled value: %d\n", doubledValue);
    sem_post(&semaphore);
    pthread_exit(NULL);
}

void* thread2_function(void* arg)
 {
    sem_wait(&semaphore);
    int fiveTimesValue = sharedData * 5;
    printf("Thread 2: Five times value: %d\n", fiveTimesValue);
    sem_post(&semaphore);
	pthread_exit(NULL);
}

