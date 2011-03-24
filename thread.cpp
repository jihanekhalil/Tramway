#include "thread.h"
#include <QDebug>

//Map pour enregistrer les threads, clés(numero du thread, pointeur vers l'objet Thread)
QMap<pthread_t, Thread *> mapThread;

//Initialize the static mutex with default attributes
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

Thread::Thread()
{
    this->etatThread = false;
    size_t stacksize;
    pthread_attr_init(&attr);
    pthread_attr_getstacksize(&attr, &stacksize);
    stacksize = stacksize * 2;
    pthread_attr_setstacksize(&attr, stacksize);
}

Thread::~Thread()
{
    this->join();
    this->stop();
}

void createThread(pthread_t pthread, Thread * thread)
{
    pthread_mutex_lock(&mutex);
    mapThread[pthread] = thread;
    pthread_mutex_unlock(&mutex);
}

Thread * getThread(pthread_t pthread)
{
    pthread_mutex_lock(&mutex);
    Thread * thread = mapThread[pthread];
    pthread_mutex_unlock(&mutex);
    return thread;
}

void *start_thread(void * param){
    Thread * t = static_cast<Thread*>(param);
    createThread(pthread_self(), t);
    t->etatThread = true;
    t->run();
    t->etatThread = false;
    qDebug() << "Thread " << t->thread << " | s'est arreté normalement";
}

void Thread::start()
{
    //test si le thread est déjà lancé
    if(this->getEtatThread())
        qDebug() << "Thread " << this->thread << " | Erreur déjà lancé";
    //test la création du thread
    else if(pthread_create(&this->thread, &this->attr, start_thread, static_cast<void *>(this)) != 0)
        qDebug() << "Thread " << this->thread << " | Erreur lors de la création";
    else
        qDebug() << "Thread " << this->thread << " | lancé avec succès";
}

void Thread::join()
{
    if (pthread_join(this->thread, NULL) != 0)
        qDebug() << "Thread " << this->thread << " | Erreur Join";
    else
        this->etatThread = false;
}

void Thread::stop()
{
    if(pthread_cancel(this->thread) != 0)
        qDebug() << "Thread " << this->thread << " | Erreur Stop";
    else
        this->etatThread = false;
}

pthread_t Thread::id()
{
    return this->thread;
}

bool Thread::getEtatThread()
{
    return this->etatThread;
}

