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

Rame::Rame(): GestionSignal()
{}

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

        if(e->getClasse() == "Feu")
        {
            Feux * f = dynamic_cast<Feux *>(e);
            f->addSignal(new Signals(this, Signals::Demande));                        
        }
        else if(e->getClasse() == "Station")
        {
            Station * s = dynamic_cast<Station *>(e);
            s->addSignal(new Signals(this, Signals::Demande));
        }
        else
            this->position++;       
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
