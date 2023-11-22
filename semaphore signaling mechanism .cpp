//semaphore signaling mechanism
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t semaphore;
void *process(void *processId) 
{
    int id = *((int *)processId);
    printf("P%d is waiting on the semaphore...\n", id);
    sem_wait(&semaphore);
    printf("P%d enters the critical section.\n", id);
    printf("P%d is using the resource.\n", id);
    int sleep(2);
    sem_post(&semaphore);
    printf("P%d releases the semaphore and exits the critical section.\n", id);
    return NULL;
}

int main() 
{
    sem_init(&semaphore, 0, 4);
    pthread_t threadIds[5];
    int processIds[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) 
	{
        pthread_create(&threadIds[i], NULL, process, &processIds[i]);
    }
    for (int i = 0; i < 5; ++i) 
	{
        pthread_join(threadIds[i], NULL);
    }
    sem_destroy(&semaphore);

    return 0;
}

