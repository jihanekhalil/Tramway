/*
 *   Copyright 2011 by Jihane Khalil <khaliljihane@gmail.com>
 *   Copyright 2011 by Paul Labonne <paul.labonne@gmail.com>
 *   Copyright 2011 by Manuel Campomanes <campomanes.manuel@gmail.com>
 *   Copyright 2011 by Marc-Antoine Beauvais <marcantoine.beauvais@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

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

void *start_thread(void * param)
{
    Thread * t = static_cast<Thread*>(param);
    createThread(pthread_self(), t);
    t->etatThread = true;
    t->run();
    t->etatThread = false;
    qDebug() << "Thread " << t->thread << " | s'est arrete normalement";
}

void Thread::start()
{    
    if (pthread_create(&this->thread, &this->attr, start_thread, static_cast<void *>(this)) != 0)
        qDebug() << "Thread " << this->thread << " | Erreur lors de la creation";    
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
    if (pthread_cancel(this->thread) != 0)
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

