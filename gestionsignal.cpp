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
        qDebug() << "creation Thread impossible";
    }

   // qDebug() << "creation Thread OK";
}

Thread * getThread(pthread_t pthread);

void GestionSignal::addSignal(Signals * s)
{
   // qDebug() << "test 01"<< this->getClasse();
    pthread_mutex_lock(&mutex);
    this->listSignals << s;
   // qDebug() << "liste signal : " << listSignals.size();
    pthread_mutex_unlock(&mutex);
   // qDebug() << "id thread " << this->id();
    int t = pthread_kill(this->id(), SIGUSR1);
    if( t<0 ) qDebug() << "Erreur Kill : " << t;
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
