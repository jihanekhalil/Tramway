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

#ifndef ELEMENT_H
#define ELEMENT_H

#include <QPainter>
#include <iostream>
#include "gestionsignal.h"

class Element : public GestionSignal
{
public:

    /**
     * @brief Constructeur de Element.
     */
    Element();

    /**
     * @brief Affichage graphique d'un element.
     * @param
     */
    virtual void afficher(QPainter * painter, int x, int y, int, int);

    /**
     * @brief Traitement des signaux reçus.
     */
    virtual void createSignal() {}
};

#endif // ELEMENT_H
