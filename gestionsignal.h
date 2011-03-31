#ifndef GESTIONSIGNAL_H
#define GESTIONSIGNAL_H

class GestionSignal;
#include "thread.h"
#include "signals.h"
#include <signal.h>
#include <QList>
#include <pthread.h>

//struct siginfo;
//typedef struct siginfo siginfo_t;

class GestionSignal : public Thread
{
public:
    GestionSignal();
    ~GestionSignal();
    void addSignal(Signals *);
    virtual void run() {}

protected:
    virtual void createSignal() = 0;
    void deleteSignal();

private:
    static void staticCreateSignals(int, siginfo_t *, void *);

protected:
    QList<Signals *> listSignals;

private:
    pthread_mutex_t mutex;
    struct sigaction signalsAction;
};

#endif // GESTIONSIGNAL_H
