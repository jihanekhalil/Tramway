#include "rame.h"

#include <QList>
#include <QDebug>
#include "feux.h"
#include "station.h"

void Rame::run()
{
    //incremente la position et regarde 2/3 cases plus loin sur la ligne
}
Rame::Rame(): Thread()
{
    //Troncon * tr = new Troncon(20);
    //this->troncon= tr;
}

Rame::Rame(Ligne *ligne): Thread(){
    this->ligne= ligne;
    this->position=0;
}

void Rame::afficher(QPainter * painter, int x, int y, int wElement,int hElement )
{
    painter->fillRect(x, y, wElement,hElement,QBrush(QColor(255,255,255)));
}

void Rame::avancer(){
    if(this->position<this->ligne->getLongueur()){
        Element * e = this->ligne->getElementAt(this->position);
        Feux * f = dynamic_cast<Feux *>(e);
        Station * s = dynamic_cast<Station *>(e);
        if(f){
            if(f->estVert()){
                f->passerRouge();
                this->position++;
            }
            else
                return;
        }
        else
            this->position++;

    }
}

int Rame::getPosition(){
    return this->position;
}

void Rame::setPosition(int p){
    this->position=p;
}
