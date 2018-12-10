#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long number = 0;
int threshold;

static pthread_mutex_t count_mutex;

void *incrementNumbers(void *arg) {
    for(long i = 0; i < 500000000; i++) {
        if(i % threshold == 0) {
            //Lock the thread so we can increment the number
            pthread_mutex_lock(&count_mutex);

            number = number + threshold;

            pthread_mutex_unlock(&count_mutex);
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    threshold = atoi(argv[1]);

    pthread_t threadOne, threadTwo, threadThree, threadFour, threadFive;

    pthread_create(&threadOne, NULL, incrementNumbers, &threshold);
    pthread_create(&threadTwo, NULL, incrementNumbers, &threshold);
    pthread_create(&threadThree, NULL, incrementNumbers, &threshold);
    pthread_create(&threadFour, NULL, incrementNumbers, &threshold);
    pthread_create(&threadFive, NULL, incrementNumbers, &threshold);

    pthread_join(threadOne, NULL);
    pthread_join(threadTwo, NULL);
    pthread_join(threadThree, NULL);
    pthread_join(threadFour, NULL);
    pthread_join(threadFive, NULL);

    printf("Number: %ld\n", number);

    return 0;
}
