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

#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>
#include <QMap>
#include <QString>

class Thread
{

public:
    /**
     * @brief constructeur de Thread.
     */
    Thread();

    /**
     * @brief Destructeur de Thread.
     */
    virtual ~Thread();

    /**
     * @brief Comportement d'un Thread.
     */
    virtual void run() = 0;

    /**
     * @brief Demarrage d'un thread.
     */
    virtual void start();

    /**
     * @brief Attente du join.
     */
    virtual void join();

    /**
     * @brief Arret du Thread.
     */
    virtual void stop();

    /**
     * @brief Retourne le nom de la classe Thread.
     * @return le nom de la classe
     */
    virtual QString getClasse() {
        return QString("Thread");
    }

    /**
     * @brief Fonction lancee lors de la creation d'un thread.
     */
    friend void * start_thread(void *);

    /**
     * @brief Retourne l'id du thread.
     * @return id du thread
     */
    pthread_t id();

    /**
     * @brief Retourne l'etat du thread.
     * @return etat du thread ACTIF=1
     */
    bool getEtatThread();

private:
    /*
     * Etat du thread
     */
    bool etatThread;

    /*
     * Thread
     */
    pthread_t thread;

    /*
     * Attributs du thread
     */
    pthread_attr_t attr;
};

Thread * getThread(pthread_t pthread);
void *start_thread(void * param);

#endif // THREAD_H
