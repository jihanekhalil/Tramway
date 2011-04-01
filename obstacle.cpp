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

#include "obstacle.h"
#include <QDebug>
Obstacle::Obstacle()
{}

Obstacle::~Obstacle()
{}

void Obstacle::afficher(QPainter *painter, int x, int y, int w, int h)
{
    QPainterPath obstacle;
    obstacle.addEllipse(x, y, w, h);

    painter->drawPath(obstacle);
    painter->fillPath(obstacle, QBrush(QColor(255, 0, 0)));
}

Obstacle::Obstacle(QList<Element *> *sens, int position)
{
    this->sens = sens;
    this->position = position;

    sleep(10);
    this->sens->replace(position, new Element());;
    delete(this);
}
