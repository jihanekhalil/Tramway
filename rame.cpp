#include "rame.h"

#include <QList>
#include <QDebug>
#include "feux.h"
#include "station.h"

void Rame::run()
{
    qDebug() << "Rame | run";
    for(;;)
    {

    }
}

void Rame::detectionPointSynchronisation()
{
    //PointSynchronisation * ps;    
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

void Rame::afficher(QPainter * painter, int x, int y)
{
    painter->fillRect(x, y, 10,3,QBrush(QColor(155,155,155)));
}

void Rame::avancer(){
    if(this->position<this->ligne->getLongueur()){
        Element * e = this->ligne->getElementAt(this->position);

        //Station * s = dynamic_cast<Station *>(e);
        qDebug() << "position : " << this->getPosition();
        qDebug() << "classe : " << e->getClasse();
        if(e->getClasse() == "Feu")
        {
            Feux * f = dynamic_cast<Feux *>(e);
            f->addSignal(new Signals(this, Signals::Demande));
            qDebug() << "envoi signal Feu";
            if(this->listSignals.empty())
            {
                qDebug() << "attend reponse";
            }
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
    if(!this->listSignals.isEmpty())
    {
        Signals * s = this->listSignals.takeFirst();
        switch(s->type())
        {
            case Signals::Arret:
            {
                qDebug() << "tram arreter";
            }
            break;
            case Signals::Passe:
            {
                s->emetteur()->addSignal(new Signals(this, Signals::EstPasse));
                this->position++;
            }
            break;
        }
    }
}

int Rame::getPosition(){
    return this->position;
}
