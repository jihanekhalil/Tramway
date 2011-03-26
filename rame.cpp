#include "rame.h"

#include <QList>
#include <QDebug>
#include "feux.h"
#include "station.h"
int Rame::nbRame = 0;

void Rame::run()
{
    qDebug() << "Rame "<< this->numRame <<" :  run";
    for(;;)
    {

    }
}

Rame::Rame(): GestionSignal()
{}

Rame::Rame(Ligne *ligne): GestionSignal()
{
    this->numRame = Rame::nbRame;
    Rame::nbRame++;

    this->ligne= ligne;
    this->position=0;
}

void Rame::afficher(QPainter * painter, int x, int y, int wElement,int hElement )
{

    painter->fillRect(x-wElement, y, wElement,hElement,QBrush(QColor(255,255,255)));
   // painter->drawLine(x, y, x, y+wElement);
}


void Rame::avancer(){
    if(this->position<this->ligne->getLongueur()){
        Element * e = this->ligne->getElementAt(this->position);

        qDebug() << "Rame "<< this->numRame <<" \t position : " << this->getPosition();

        if(e->getClasse() == "Feu")
        {
            qDebug() << "A";
            Feux * f = dynamic_cast<Feux *>(e);
            f->addSignal(new Signals(this, Signals::Demande));
            qDebug() << "Rame "<< this->numRame <<" \t > envoi signal Feu" << f->getNum()<< ".";
            if(this->listSignals.empty())
            {
                qDebug() << "Rame "<< this->numRame <<" \t attend reponse Feu" << f->getNum()<< ".";
            }
        }
        else if(e->getClasse() == "Station")
        {
            qDebug() << "B";
            qDebug() << "Rame "<< this->numRame <<" \t arrive a station ";
            Station * s = dynamic_cast<Station *>(e);
            s->addSignal(new Signals(this, Signals::Demande));
        }
        else{

            qDebug() << "C";
            this->position++;
        }
    }

}

void Rame::createSignal(){
    if(!this->listSignals.isEmpty())
    {
        Signals * s = this->listSignals.takeFirst();
        switch(s->type())
        {
            case Signals::Arret:
            {
                qDebug() << "Rame "<< this->numRame <<" \t Arret";
            }
            break;
            case Signals::Passe:
            {
               qDebug() << "Rame "<< this->numRame <<" \t > envoi Signals::EstPasse a "<< s->emetteur()->getClasse();
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
void Rame::setPosition(int i){
     this->position = i;
}
