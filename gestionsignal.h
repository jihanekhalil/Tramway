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

#ifndef GESTIONSIGNAL_H
#define GESTIONSIGNAL_H

class GestionSignal;

#include "thread.h"
#include "signals.h"
#include <signal.h>
#include <QList>
#include <pthread.h>

class GestionSignal : public Thread
{
public:
    /**
     * @brief Constructeur d'un gestionnaire de signaux.
     */
    GestionSignal();
    
    /**
     * @brief Destructeur du gestionnaire de signaux.
     */
    ~GestionSignal();
    
    /**
     * @brief Ajout d'un signal à la liste de signaux.
     * @param Un signal
     */
    void addSignal(Signals *);
    
    virtual void run() {}

protected:    
    virtual void createSignal() = 0;

    /**
     * @brief Supprime un signal de la liste des signaux.
     */
    void deleteSignal();

private:
    static void staticCreateSignals(int, siginfo_t *, void *);

protected:
    /*
     * Liste des signaux.
     */
    QList<Signals *> listSignals;

private:
    pthread_mutex_t mutex;
    struct sigaction signalsAction;
};

#endif // GESTIONSIGNAL_H
