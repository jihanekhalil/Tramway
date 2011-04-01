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

#ifndef FEUX_H
#define FEUX_H

#include "pointsynchronisation.h"
#include <iostream>
#include "thread.h"
#include "ligne.h"

class Feux : public PointSynchronisation
{

public:

    /**
     * @brief constructeur de Feu.
     */
    Feux();        

    /**
     * @brief Constructeur de Feu.
     * @param une ligne
     */
    Feux(Ligne *);

    /**
     * @brief Destructeur de Feu.
     */
    ~Feux();

    /**
     * @brief Comportement d'un feu.
     */
    void run();   

    /**
     * @brief Affichage graphique d'un feu.
     * @param
     */
    virtual void afficher(QPainter * painter, int x, int y, int, int);


    /**
     * @brief Retourne le nom de la classe Feu.
     * @return le nom de la classe
     */
    virtual QString getClasse() {
        return QString("Feu");
    }

    /**
     * @brief Traitement des signaux reçus.
     */
    void createSignal();

public:

    static int nombreFeux;

private:
    /*
     * Ligne du feu.
     */
    Ligne * ligne;

    /*
     * Position du feu sur la ligne.
     */
    int position;
};

#endif // FEUX_H
