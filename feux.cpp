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

#include "feux.h"
#include "ligne.h"
#include <QDebug>

void Feux::run()
{
    for (;;) {
        sleep(1);
    }
}

Feux::~Feux()
{
    delete ligne;
}

int Feux::nombreFeux = 0;
Feux::Feux(): PointSynchronisation()
{
}

Feux::Feux(Ligne * ligne): PointSynchronisation()
{
    this->ligne = ligne;

    Feux::nombreFeux++;
    this->numPS = Feux::nombreFeux;
}
void Feux::afficher(QPainter * painter, int x, int y, int wElement, int hElement)
{
    QPainterPath feu;
    QVector<QPointF> points;
    points.push_back(QPointF((qreal) x, (qreal) y + hElement));
    points.push_back(QPointF((qreal) x - (wElement / 4), (qreal) y + (2*hElement)));
    points.push_back(QPointF((qreal) x + (wElement / 4), (qreal) y + (2*hElement)));
    feu.addPolygon(QPolygonF(points));
    // feu.addEllipse(x, y-2*hElement, wElement, wElement);
    painter->drawPath(feu);
    if (this->estVert())
        painter->fillPath(feu, QBrush(QColor(0, 255, 0)));
    else
        painter->fillPath(feu, QBrush(QColor(255, 0, 0)));

}

void Feux::createSignal()
{
    while (this->listSignals.size()) {
        Signals * s = this->listSignals.takeFirst();
        switch (s->type()) {
        case Signals::Demande: {            
            if (!this->estVert()) {
                qDebug() << this->suivant->getClasse();
                if (this->suivant != NULL) {
                    qDebug() << this->suivant->getDerniereRame() << "-" << this->derniereRame;
                    if (this->suivant->getDerniereRame() != this->derniereRame) {
                        qDebug() << "Feu " << this->numPS << "\t rouge.";
                        s->emetteur()->addSignal(new Signals(this, Signals::Arret));
                    } else {
                        this->passerVert();
                        s->emetteur()->addSignal(new Signals(this, Signals::Passe));
                    }
                } else {
                    qDebug() << "Feu " << this->numPS << "\t rouge.";
                    s->emetteur()->addSignal(new Signals(this, Signals::Arret));
                }
            } else {                
                s->emetteur()->addSignal(new Signals(this, Signals::Passe));
            }
        }
        break;
        case Signals::EstPasse: {
            usleep(200000);
            qDebug() << "Feu " << this->numPS << "\t Tram passe, passe rouge.";
            this->passerRouge();
            if (this->getPrecedent() != NULL && this->getPrecedent()->getClasse() != "Station")
                this->getPrecedent()->passerVert();
            this->derniereRame = s->emetteur();
        }
        break;
        }
    }
}
