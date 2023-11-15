#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *myThreadFun(void *vargp) {
    printf("Printing from Thread\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_id;
    printf("Before Thread\n");
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_join(thread_id, NULL);
    printf("After Thread\n");
    exit(0);
}
