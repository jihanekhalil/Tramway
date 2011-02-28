#ifndef THREAD_H
#define THREAD_H
#include <pthread.h>
class Thread
{
    pthread_t t;
public:
    Thread();
    virtual void run() = 0;
    void start();
    friend void * start_thread(void *);
};

#endif // THREAD_H
