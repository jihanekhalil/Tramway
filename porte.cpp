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

#include "porte.h"
#include <QDebug>

int Porte::nombrePortes = 0;

Porte::~Porte()
{
    delete rame;
}

void Porte::run()
{
    qDebug() << "Porte   run";
    for (;;) {
        sleep(1);
    }
}
void Porte::createSignal()
{

    while (this->listSignals.size()) {
        Signals *s = this->listSignals.takeFirst();
        switch (s->type()) {
        case Signals::OuvrirPorte: {
            this->ouvrir();
            qDebug() << "Rame " << this->rame->getNumRame() << " \t porte " << this->numPorte << " ouverte.";
        }
        break;
        case Signals::FermerPorte: {
            this->fermer();
            qDebug() << "Rame " << this->rame->getNumRame() << " \t porte " << this->numPorte << " fermee.";
            s->emetteur()->addSignal(new Signals(this, Signals::PorteFermee));
        }
        break;
        }
    }
}

Porte::Porte(): GestionSignal() {}


Porte::Porte(Rame *r): GestionSignal()
{
    this->rame = r;
    this->open = false;
    Porte::nombrePortes++;
    this->numPorte = Porte::nombrePortes;
}
bool Porte::isOpen()
{
    return this->open;
}

void Porte::fermer()
{
    this->open = false;
    this->ouvertureDemandee = true;
}

// ouvre la porte si l'ouverture a été demandée
void Porte::ouvrir()
{
    if (this->ouvertureDemandee) {
        this->open = true;
    }
}

// demande l'ouverture de la porte
void Porte::demanderOuverture()
{
    if (!this->ouvertureDemandee && !this->open) {
        this->ouvertureDemandee = true;
    }
}


void Porte::afficher(QPainter * painter, int x, int y, int wElement, int hElement)
{
    if (this->isOpen())
        painter->setPen(QColor(0, 255, 0));
    else
        painter->setPen(QColor(255, 0, 0));
    painter->drawLine(x, y, x + wElement, y);
    painter->setPen(QColor(0, 0, 0));
}
