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

#include "pointsynchronisation.h"
#include <QDebug>

PointSynchronisation::PointSynchronisation()
{
    this->vert = true;
    this->suivant = NULL;
}

PointSynchronisation::~PointSynchronisation()
{
    delete derniereRame;
    delete suivant;
}

void PointSynchronisation::afficher(QPainter * painter, int x, int y, int x1, int x2)
{


}

void PointSynchronisation::passerVert()
{
    qDebug() << this->getClasse() << " " << this->numPS << "\tpasse Vert.";
    this->vert = true;
}

void PointSynchronisation::passerRouge()
{
    qDebug() << this->getClasse() << " " << this->numPS << "\tpasse Rouge.";
    this->vert = false;
}
bool PointSynchronisation::estVert()
{
    return this->vert;
}
int PointSynchronisation::getNum()
{
    return this->numPS;
}
GestionSignal * PointSynchronisation::getDerniereRame()
{
    return this->derniereRame;
}

PointSynchronisation * PointSynchronisation::getSuivant()
{
    return this->suivant;
}

void PointSynchronisation::setSuivant(PointSynchronisation *ps)
{
    this->suivant = ps;
}

PointSynchronisation * PointSynchronisation::getPrecedent()
{
    return this->precedent;
}

void PointSynchronisation::setPrecedent(PointSynchronisation * ps)
{
    this->precedent = ps;
}
