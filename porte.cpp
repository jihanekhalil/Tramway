#include "porte.h"
#include <QDebug>

int Porte::nombrePortes=0;

void Porte::run()
{
    qDebug() << "Porte   run";
    for(;;)
    {
        sleep(1);
    }
}
void Porte::createSignal(){

    while(this->listSignals.size())
    {
        Signals *s= this->listSignals.takeFirst();
        switch(s->type())
        {
            case Signals::OuvrirPorte:
            {
                this->ouvrir();
                qDebug() << "Rame "<< this->rame->getNumRame() <<" \t porte "<< this->numPorte <<" ouverte.";
            }
            break;
            case Signals::FermerPorte:
            {
               this->fermer();
               qDebug() << "Rame "<< this->rame->getNumRame() <<" \t porte "<< this->numPorte <<" fermee.";
               s->emetteur()->addSignal(new Signals(this, Signals::PorteFermee));
            }
            break;
        }
        this->listSignals->removeFirst();
    }
}

Porte::Porte(): GestionSignal(){}


Porte::Porte(Rame *r): GestionSignal()
{
    this->rame=r;
    this->open=false;
    this->ouvertureDemandee=true;
    this->addSignal(new Signals(this, Signals::OuvrirPorte));
    Porte::nombrePortes++;
    this->numPorte = Porte::nombrePortes;
}
bool Porte::isOpen(){
    return this->open;
}

void Porte::fermer(){
    this->open=false;
    this->ouvertureDemandee = true;
}

// ouvre la porte si l'ouverture a été demandée
void Porte::ouvrir(){
    if(this->ouvertureDemandee){
        this->open=true;
    }
}

// demande l'ouverture de la porte
void Porte::demanderOuverture(){
    if(!this->ouvertureDemandee && !this->open){
        this->ouvertureDemandee=true;
    }
}


void Porte::afficher(QPainter * painter, int x, int y, int wElement,int hElement ){
    if(this->isOpen())
        painter->setPen(QColor(0,255,0));
    else
        painter->setPen(QColor(255,0,0));
    painter->drawLine(x, y, x+wElement, y);
        painter->setPen(QColor(0,0,0));
}
