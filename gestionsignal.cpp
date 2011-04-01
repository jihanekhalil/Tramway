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

#include "gestionsignal.h"
#include <QDebug>

GestionSignal::GestionSignal()
{
    pthread_mutex_init(&mutex, NULL);
    sigemptyset(&this->signalsAction.sa_mask);
    this->signalsAction.sa_flags = SA_SIGINFO;
    this->signalsAction.sa_sigaction = GestionSignal::staticCreateSignals;

    //test creation thread --> à enlever
    if (sigaction(SIGUSR1, &this->signalsAction, NULL)) {
        qDebug() << "creation Thread impossible";
    }
}

GestionSignal::~GestionSignal()
{
    for (int i = 0; i < this->listSignals.size(); i++)
        delete this->listSignals.at(i);
}

Thread * getThread(pthread_t pthread);

void GestionSignal::addSignal(Signals * s)
{    
    pthread_mutex_lock(&mutex);
    this->listSignals << s;    
    pthread_mutex_unlock(&mutex);    
    int t = pthread_kill(this->id(), SIGUSR1);
    if (t < 0) qDebug() << "Erreur Kill : " << t;
}

void GestionSignal::deleteSignal()
{
    if (!this->listSignals.isEmpty())
        this->listSignals.removeFirst();
}

void GestionSignal::staticCreateSignals(int sig, siginfo_t *si, void *uc)
{
    GestionSignal * gs = (GestionSignal *) getThread(pthread_self());
    gs->createSignal();
}
