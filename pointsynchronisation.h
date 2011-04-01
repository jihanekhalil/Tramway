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

#ifndef POINTSYNCHRONISATION_H
#define POINTSYNCHRONISATION_H

#include <iostream>
#include <QPainter>
#include "element.h"
#include "rame.h"

class PointSynchronisation: public Element
{
public:
    
    /**
     * @brief Constructeur d'un point.
     */
    PointSynchronisation();
    
    /**
     * @brief Destructeur d'un point de synchronisation.
     */
    ~PointSynchronisation();

    /**
     * @brief Affichage graphique d'un Point.
     * @param
     */
    virtual void afficher(QPainter * painter, int x, int y, int , int);

    /**
     * @brief Savoir si un point est accessible.
     * @return l'etat du point
     */
    bool estVert();

    /**
     * @brief Recuperer la la derniere rame.
     * @return Une liste de station
     */
    GestionSignal * getDerniereRame();

    /**
     * @brief Definir un point comme inaccessible.
     */
    void passerRouge();

    /**
     * @brief Definir un point comme accessible.
     */
    void passerVert();

    /**
     * @brief Definir le point suivant.
     * @param Un point
     */
    void setSuivant(PointSynchronisation *);

    /**
     * @brief Recuperer le point suivant.
     * @return Le point suivant
     */
    PointSynchronisation * getSuivant();

    /**
     * @brief Definir le point precedent.
     * @param Un point
     */
    void setPrecedent(PointSynchronisation *);

    /**
     * @brief Recuperer le point precedent.
     * @return Le point precedent
     */
    PointSynchronisation * getPrecedent();

    /**
     * @brief Recuperer le numero du point courant.
     * @return Le numero du point courant
     */
    int getNum();

protected:
    /*
     * etat du point : accessible (true) ou inaccessible (false)
     */
    bool vert;

    /*
     * Identificateur du point de synchro
     */
    int numPS;

    /*
     * Derniere rame passee
     */
    GestionSignal * derniereRame;

    /*
     * Point suivant de la ligne.
     */
    PointSynchronisation * suivant;

    /*
     * Point precedent de la ligne.
     */
    PointSynchronisation * precedent;

};

#endif // POINTSYNCHRONISATION_H
