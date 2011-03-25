#include "rame.h"

#include <QList>
#include <QDebug>
#include "feux.h"
#include "station.h"

void Rame::run()
{
    qDebug() << "Rame | run";
    detectionPointSynchronisation();
}

void Rame::detectionPointSynchronisation()
{
    //PointSynchronisation * ps;
    qDebug() << "position " << this->getPosition();
    //this->ligne->ElementExists(this->getPosition());
}

Rame::Rame(): GestionSignal()
{
    //Troncon * tr = new Troncon(20);
    //this->troncon= tr;
}

Rame::Rame(Ligne *ligne): GestionSignal()
{
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

        //Station * s = dynamic_cast<Station *>(e);

        if(e->getClasse() == "Feu")
        {
            Feux * f = dynamic_cast<Feux *>(e);
            f->addSignal(new Signals(this, Signals::Demande));
        }
        else
            this->position++;
       //
//        if(f){
//            if(f->estVert()){
//                f->passerRouge();
//                this->position++;
//            }
//            else
//                return;
//        }
//        else
//            this->position++;

    }
}

void Rame::createSignal()
{

}

int Rame::getPosition(){
    return this->position;
}

void Rame::setPosition(int p){
    this->position=p;
}
