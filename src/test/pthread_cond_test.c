#include "pthread.h"

struct {
    pthread_mutex_t mutex;
    int nput;
    int nval;
} put = { PTHREAD_MUTEX_INITIALIZER };

struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int nready;
} nready = { PTHREAD_MUTEX_ITITIALIZER, PTHREAD_COND_INITIALIZER };

int main(int argc, char *argv[]) {

    return 0;
}

