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
    if (pthread_equal(thread_id1, thread_id2)) {
        printf("Threads are equal\n");
    } else {
        printf("Threads are not equal\n");
    }
    printf("After Threads\n");
    exit(0);
}
