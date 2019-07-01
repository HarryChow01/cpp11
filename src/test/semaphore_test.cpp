
#include <cstdio>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define BUFFSIZE 10
int buff[BUFFSIZE];

sem_t sem_nempty;
sem_t sem_nstored;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int i1 = 1, i2 = 2;

void* produce(void* arg) {
    int index = 0;
    int i = 0;
    while (1) {
        sem_wait(&sem_nempty);
        pthread_mutex_lock(&mutex);
        buff[index++] = i++;
        index %= BUFFSIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&sem_nstored);
    }
}

void* consume(void* arg) {
    int index = 0;
    int& thread_num = *((int*)arg);
    while (1) {
        sem_wait(&sem_nstored);
        pthread_mutex_lock(&mutex);
        printf("consumer%d: buff[%d] = %d\n", thread_num, index, buff[index]);
        sleep(1);
        index %= BUFFSIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&sem_nempty);
    }
}

int main(int argc, char* argv[]) {
    sem_init(&sem_nempty, 0, BUFFSIZE);
    sem_init(&sem_nstored, 0, 0);
    pthread_t producer1, producer2, consumer1, consumer2;

    pthread_create(&producer1, NULL, produce, NULL);
    pthread_create(&producer2, NULL, produce, NULL);
    pthread_create(&consumer1, NULL, consume, &i1);
    pthread_create(&consumer2, NULL, consume, &i2);

    pthread_join(producer1, NULL);
    pthread_join(producer2, NULL);
    pthread_join(consumer1, NULL);
    pthread_join(consumer2, NULL);

    return 0;
}











