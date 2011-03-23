#include "gestionsignal.h"
#include <QDebug>

GestionSignal::GestionSignal()
{
    pthread_mutex_init(&mutex, NULL);
    sigemptyset(&this->signalsAction.sa_mask);
    this->signalsAction.sa_flags = SA_SIGINFO;
    this->signalsAction.sa_sigaction = GestionSignal::staticCreateSignals;

    //test creation thread --> à enlever
    if(sigaction(SIGUSR1, &this->signalsAction, NULL))
    {
        qDebug() << "création Thread impossible";
    }
}

Thread * getThread(pthread_t pthread);

void GestionSignal::addSignal(Signals * s)
{
    pthread_mutex_lock(&mutex);
    this->listSignals.append(s);
    pthread_mutex_unlock(&mutex);
    pthread_kill(this->id(), SIGUSR1);
}

void GestionSignal::deleteSignal()
{
    if(!this->listSignals.isEmpty())
        this->listSignals.removeFirst();
}

void GestionSignal::staticCreateSignals(int sig, siginfo_t *si, void *uc)
{
    GestionSignal * gs = (GestionSignal *) getThread(pthread_self());
    gs->createSignal();
}
