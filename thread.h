#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>
#include <QMap>
#include <QString>

class Thread
{

public:
    Thread();
    virtual ~Thread();
    virtual void run() = 0;
    virtual void start();
    virtual void join();
    virtual void stop();
    virtual QString getClasse() {
        return QString("Thread");
    }
    friend void * start_thread(void *);
    pthread_t id();
    bool getEtatThread();

private:
    bool etatThread;
    pthread_t thread;
    pthread_attr_t attr;
};

Thread * getThread(pthread_t pthread);
void *start_thread(void * param);

#endif // THREAD_H
