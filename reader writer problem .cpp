//reader writer problem using threads
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define NUM_READERS 5
#define NUM_WRITERS 5
pthread_t readerThreads[NUM_READERS], writerThreads[NUM_WRITERS];
sem_t mutex, resourceAccess, readCountAccess;
int readCount = 0;
void *reader(void *arg)
 {
	int readerId = *((int *)arg);
    while (1) 
	{
        sem_wait(&readCountAccess);
        readCount++;
        if (readCount == 1) 
		{
            sem_wait(&resourceAccess);
        }
        sem_post(&readCountAccess);
        printf("Reader %d is reading.\n", readerId);
        sem_wait(&readCountAccess);
        readCount--;
        if (readCount == 0) 
		{
            sem_post(&resourceAccess);
        }
        sem_post(&readCountAccess);
        sleep(1);
    }

    return NULL;
}
void *writer(void *arg)
 {
    int writerId = *((int *)arg);

    while (1) 
	{
        sem_wait(&resourceAccess);
        printf("Writer %d is writing.\n", writerId);
        sem_post(&resourceAccess);
        sleep(1);
    }
   return NULL;
}
int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&resourceAccess, 0, 1);
    sem_init(&readCountAccess, 0, 1);
    int readerIds[NUM_READERS], writerIds[NUM_WRITERS];
    for (int i = 0; i < NUM_READERS; ++i)
	 {
        readerIds[i] = i + 1;
        pthread_create(&readerThreads[i], NULL, reader, &readerIds[i]);
    }
    for (int i = 0; i < NUM_WRITERS; ++i) 
	{
        writerIds[i] = i + 1;
        pthread_create(&writerThreads[i], NULL, writer, &writerIds[i]);
    }
    for (int i = 0; i < NUM_READERS; ++i)
	 {
        pthread_join(readerThreads[i], NULL);
    }
    for (int i = 0; i < NUM_WRITERS; ++i) 
	{
        pthread_join(writerThreads[i], NULL);
    }
    sem_destroy(&mutex);
    sem_destroy(&resourceAccess);
    sem_destroy(&readCountAccess);
    return 0;
}

