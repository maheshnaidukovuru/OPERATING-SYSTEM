//dining philosopher
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
pthread_mutex_t mutex;
pthread_cond_t condition[NUM_PHILOSOPHERS];
int state[NUM_PHILOSOPHERS];

void test(int i) 
{
    if (state[i] == HUNGRY &&
        state[(i + 4) % 5] != EATING &&
        state[(i + 1) % 5] != EATING) 
		{
        state[i] = EATING;
        printf("Philosopher %d is Eating.\n", i);
        pthread_cond_signal(&condition[i]);
       }
}

void pickup_forks(int philosopher_number) {
    pthread_mutex_lock(&mutex);
    state[philosopher_number] = HUNGRY;
    printf("Philosopher %d is Hungry.\n", philosopher_number);
    test(philosopher_number);
    while (state[philosopher_number] != EATING) {
        pthread_cond_wait(&condition[philosopher_number], &mutex);
    }
    pthread_mutex_unlock(&mutex);
}

void return_forks(int philosopher_number) {
    pthread_mutex_lock(&mutex);
    state[philosopher_number] = THINKING;
    printf("Philosopher %d is Thinking.\n", philosopher_number);

    test((philosopher_number + 4) % 5);
    test((philosopher_number + 1) % 5);

    pthread_mutex_unlock(&mutex);
}

void *philosopher(void *arg) 
{
    int philosopher_number = *(int *)arg;
    while (1) 
	{
        sleep(rand() % 3 + 1);// Hungry, want to eat
        pickup_forks(philosopher_number);// Eating
        sleep(rand() % 3 + 1);// Done eating, release forks
		return_forks(philosopher_number);
    }
}

int main() 
{
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_numbers[NUM_PHILOSOPHERS];
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i)
	 {
        pthread_cond_init(&condition[i], NULL);
        philosopher_numbers[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, (void *)&philosopher_numbers[i]);
    }
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) 
	{
        pthread_join(philosophers[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) 
	{
        pthread_cond_destroy(&condition[i]);
    }
    return 0;
}

