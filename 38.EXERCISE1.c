#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
#define LEFT (i + N - 1) % N
#define RIGHT (i + 1) % N
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];
int phil[N] = {0, 1, 2, 3, 4};
sem_t mutex;
sem_t s[N];

void test(int i) {
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[i] = EATING;
        sleep(2);
        printf("Philosopher %d takes fork %d and %d\n", i + 1, LEFT + 1, i + 1);
        printf("Philosopher %d is Eating\n", i + 1);
        sem_post(&s[i]);
    }
}

void take_fork(int i) {
    sem_wait(&mutex);
    state[i] = HUNGRY;
    printf("Philosopher %d is Hungry\n", i + 1);
    test(i);
    sem_post(&mutex);
    sem_wait(&s[i]);
    sleep(1);
}

void put_fork(int i) {
    sem_wait(&mutex);
    state[i] = THINKING;
    printf("Philosopher %d puts fork %d and %d down\n", i + 1, LEFT + 1, i + 1);
    printf("Philosopher %d is thinking\n", i + 1);
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}

void *philosopher(void *arg) {
    while (1) {
        int *i = arg;
        sleep(1);
        take_fork(*i);
        sleep(0);
        put_fork(*i);
    }
}

int main() {
    int i;
    pthread_t thread_id[N];
    sem_init(&mutex, 0, 1);
    for (i = 0; i < N; i++)
        sem_init(&s[i], 0, 0);
    for (i = 0; i < N; i++)
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
    for (i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL);
    return 0;
}
