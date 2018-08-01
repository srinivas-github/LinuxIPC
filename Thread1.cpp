#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

void* printHello(void* args)
{
    long tid = (long)args;
    printf("Created thread: %ld\n", tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    
    for (int i = 0; i < NUM_THREADS; i++)
    {
        printf("Mian: creating thread: %d\n", i);
        int rc = pthread_create(&threads[i], NULL, printHello, (void*)i);
        if (rc)
            exit(-1);
    }
    pthread_exit(NULL);
    return 0;
}
