#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *myThreadFun(void *vargp) {
    printf("Printing from Thread\n");
    return NULL;
}

int main() {
    pthread_t thread_id1, thread_id2;
    printf("Before Threads\n");
    pthread_create(&thread_id1, NULL, myThreadFun, NULL);
    pthread_create(&thread_id2, NULL, myThreadFun, NULL);
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    printf("After Threads\n");
    exit(0);
}
