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

#include "rame.h"
#include <QList>
#include <QDebug>
#include "feux.h"
#include "station.h"

int Rame::nbRame = 0;

Rame::~Rame()
{
    delete ligne;
    for (int i = 0; i < this->portesDroite.size(); i++)
        delete this->portesDroite.at(i);
    for (int i = 0; i < this->portesGauche.size(); i++)
        delete this->portesGauche.at(i);
}

void Rame::run()
{
    qDebug() << "Rame " << this->numRame << " :  run";
    for (;;) {
        sleep(1);
    }
}

Rame::Rame(): GestionSignal()
{}

Rame::Rame(Ligne *ligne): GestionSignal()
{
    Rame::nbRame++;
    this->numRame = Rame::nbRame;
    this->sens = Rame::Aller;
    this->ligne = ligne;
    this->position = 0;
    pthread_mutex_init(&this->mutex, NULL);
    this->nbPortes = 2;
    this->nbPortesOuvertes = 0;

    Porte::nombrePortes = 0;
    for (int i = 0; i < this->nbPortes; i++) {
        Porte * p1 = new Porte(this);
        Porte * p2 = new Porte(this);
        p1->start();
        p2->start();
        this->portesDroite.push_back(p1);
        this->portesGauche.push_back(p2);
    }
}

void Rame::afficher(QPainter * painter, int x, int y, int wElement, int hElement)
{

    painter->fillRect(x - wElement, y, wElement, hElement, QBrush(QColor(255, 255, 255)));
    int xPorteOrigine = x - wElement;
    QFont font(QString("Helvetica"));
    font.setBold(true);
    font.setPixelSize(10);
    QString nb();

    painter->setFont(font);
    painter->drawText(x - wElement + 1, y + hElement - 2, QString::number(getNbPassager()));
    int wPorte = wElement / this->nbPortes;
    for (int i = 0; i < this->nbPortes ; i++) {
        this->portesGauche.at(i)->afficher(painter,  xPorteOrigine,  y + hElement, wPorte , hElement);
        this->portesDroite.at(i)->afficher(painter,  xPorteOrigine,  y,  wPorte, hElement);
        xPorteOrigine += wPorte;
    }
}


void Rame::avancer()
{
    pthread_mutex_lock(&mutex);
    if (this->position == 0 && this->sens == Rame::Retour) {
        qDebug() << "Changement";
        this->setPosition(0);
        this->sens = Rame::Aller;
        this->position++;
    } else if (this->position == this->ligne->getLongueur() && this->sens == Rame::Aller) {
        qDebug() << "Changement";
        this->setPosition(this->ligne->getLongueur());
        this->sens = Rame::Retour;
        this->position--;
    } else if (this->position < this->ligne->getLongueur()) {
        bool aller = true;
        if (this->sens == Rame::Retour) {
            aller = false;
        }
        Element * e = this->ligne->getElementAt(this->position, aller);

        qDebug() << "Rame " << this->numRame << " \t position : " << this->getPosition();

        if (e->getClasse() == "Feu") {
            Feux * f = dynamic_cast<Feux *>(e);
            f->addSignal(new Signals(this, Signals::Demande));
            qDebug() << "Rame " << this->numRame << " \t > envoi signal Feu" << f->getNum() << ".";
            if (this->listSignals.empty()) {
                qDebug() << "Rame " << this->numRame << " \t attend reponse Feu" << f->getNum() << ".";
            }
        } else if (e->getClasse() == "Station") {
            Station * s = dynamic_cast<Station *>(e);
            s->addSignal(new Signals(this, Signals::Demande));
            qDebug() << "Rame " << this->numRame << " \t arrive a station " << s->getNom();

        } else {
            bool obstacle = false;
            if (this->position < this->ligne->getLongueur() - 1) {
                Element * suivant;
                if (aller)
                    suivant = this->ligne->getElementAt(this->position + 1, aller);
                else
                    suivant = this->ligne->getElementAt(this->position - 1, aller);

                if (suivant->getClasse() == "Obstacle") {
                    obstacle = true;
                    qDebug() << "Rame " << this->numRame << " \t Obstacle détecté";
                }
            }
            if (!obstacle)
                if (this->sens == Rame::Aller) {
                    this->position++;
                } else {
                    this->position--;
                }
        }
    }

    pthread_mutex_unlock(&mutex);

}

void Rame::createSignal()
{
    pthread_mutex_lock(&mutex);
    while (!this->listSignals.isEmpty()) {
        Signals * s = this->listSignals.takeFirst();
        switch (s->type()) {
        case Signals::Arret: {
            qDebug() << "Rame " << this->numRame << " \t Arret";
            if (s->emetteur()->getClasse() == "Station") {
                if (this->nbPortesOuvertes < this->nbPortes)
                    for (int i = 0; i < this->nbPortes ; i++) {
                        if (this->sens == Rame::Aller) {
                            this->portesGauche.at(i)->addSignal(new Signals(this, Signals::OuvrirPorte));
                            qDebug() << "Rame " << this->numRame << " \t > ouverture porte gauche " << this->portesGauche.at(i)->getNumPorte();
                        } else {
                            this->portesDroite.at(i)->addSignal(new Signals(this, Signals::OuvrirPorte));
                            qDebug() << "Rame " << this->numRame << " \t > ouverture porte droite " << this->portesDroite.at(i)->getNumPorte();
                        }

                    }
                this->nbPortesOuvertes = this->nbPortes;
            }
            pthread_mutex_unlock(&mutex);
        }
        break;
        case Signals::Passe: {
            if (s->emetteur()->getClasse() == "Station") {
                if (this->nbPortesOuvertes > 0) {
                    for (int i = 0; i < this->nbPortes ; i++) {
                        if (this->sens == Rame::Aller) {
                            this->portesGauche.at(i)->addSignal(new Signals(this, Signals::FermerPorte));
                        } else
                            this->portesDroite.at(i)->addSignal(new Signals(this, Signals::FermerPorte));
                    }
                }
            } else {
                qDebug() << "Rame " << this->numRame << " \t > envoi Signals::EstPasse a " << s->emetteur()->getClasse();
                s->emetteur()->addSignal(new Signals(this, Signals::EstPasse));
                if (sens == Rame::Aller) {
                    this->position++;
                } else {
                    this->position--;
                }

            }
            pthread_mutex_unlock(&mutex);
        }
        break;
        case Signals::PorteFermee: {
            bool aller = true;
            if (this->sens == Rame::Retour)
                aller = false;

            this->nbPortesOuvertes--;
            if (this->nbPortesOuvertes == 0) {
                qDebug() << "Rame " << this->numRame << " \t portes fermees - Depart";
                qDebug() << "Rame " << this->numRame << " \t > envoi Signals::EstPasse station a " << this->ligne->getElementAt(this->position, aller)->getClasse();

                int postmp = this->position;

                if (sens == Rame::Aller) {
                    this->position++;
                } else {
                    this->position--;
                }
                this->ligne->getElementAt(postmp, aller)->addSignal(new Signals(this, Signals::EstPasse));


            }
            pthread_mutex_unlock(&mutex);
        }
        break;
        }
    }
}

int Rame::getPosition()
{
    return this->position;
}
void Rame::setPosition(int i)
{
    this->position = i;
}

int Rame::getNumRame()
{
    return this->numRame;
}

int Rame::getNbPassager()
{
    return this->listePassager.size();
}

void Rame::monte(QList<Passager *> plistepassager)
{
    for (int i = 0; i < plistepassager.size(); i++) {
        this->listePassager.push_back(plistepassager.at(i));
    }
}

QList <Passager *> Rame::descend(Station * pstation)
{
    QList <Passager *> listedescend;
    QList <int> listeadel;
    for (int i = 0; i < this->listePassager.size(); i++) {
        if (this->listePassager.at(i)->getStationDest()->getNom() == pstation->getNom()) {
            listeadel.push_back(i);
            listedescend.push_back(this->listePassager.at(i));
        }
    }

    for (int i = 0; i < listeadel.size(); i++) {
        this->listePassager.removeAt(listeadel.at(i));
    }

    return listedescend;
}

void Rame::razListePassager()
{
    this->listePassager.clear();
}
