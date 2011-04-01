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

#ifndef SIGNALS_H
#define SIGNALS_H

class Signals;

#include "gestionsignal.h"

class Signals
{
public:
    /*
     * ENUM Type du signal
     */
    enum TypeSignal {
        Demande,
        EstPasse,
        Arret,
        Passe,
        OuvrirPorte,
        FermerPorte,
        PorteFermee
    };

public:
    /**
     * @brief constructeur de Signal.
     */
    Signals(GestionSignal*, TypeSignal);

    /**
     * @brief Destructeur de Feu.
     */
    ~Signals();

    /**
     * @brief Retourne l'emetteur du signal.
     * @return signal emetteur
     */
    GestionSignal * emetteur();

    /**
     * @brief Definir l'emetteur du signal.
     * @param signal emetteur
     */
    void setEmetteur(GestionSignal *);

    /**
     * @brief Retourne le type du signal.
     * @return type du signal
     */
    TypeSignal type();

private:
    /*
     * Type du signal
     */
    TypeSignal sigType;

    /*
     * Emetteur du signal
     */
    GestionSignal * sigEmetteur;

};

#endif // SIGNALS_H
