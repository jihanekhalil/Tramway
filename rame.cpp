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
    this->sens=Rame::Aller;
    this->ligne= ligne;
    this->position=0;
    pthread_mutex_init(&this->mutex,NULL);
    this->nbPortes= 2;
    this->nbPortesOuvertes=0;

    Porte * p1;
    Porte * p2;

    for(int i = 0; i< this->nbPortes; i++){
        p1 = new Porte(this);
        p2 = new Porte(this);
        this->portesDroite.push_back(p1);
        this->portesGauche.push_back(p2);
    }
}

void Rame::afficher(QPainter * painter, int x, int y, int wElement,int hElement )
{

    painter->fillRect(x-wElement, y, wElement,hElement,QBrush(QColor(255,255,255)));
   // painter->drawLine(x, y, x, y+wElement);
}


void Rame::avancer(){
    pthread_mutex_lock(&mutex);
    if(this->position<this->ligne->getLongueur()){
        Element * e = this->ligne->getElementAt(this->position);

        qDebug() << "Rame "<< this->numRame <<" \t position : " << this->getPosition();

        if(e->getClasse() == "Feu")
        {
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
            qDebug() << "Rame "<< this->numRame <<" \t arrive a station ";

            Station * s = dynamic_cast<Station *>(e);
            s->addSignal(new Signals(this, Signals::Demande));

            for(int i= 0; i<this->nbPortes && this->nbPortesOuvertes<this->nbPortes; i++)
            {
                if(this->sens=Rame::Aller){
                    this->portesGauche.at(i)->start();
                    this->portesGauche.at(i)->addSignal(new Signals(this, Signals::OuvrirPorte));
                }else{
                    this->portesGauche.at(i)->start();
                    this->portesDroite.at(i)->addSignal(new Signals(this, Signals::OuvrirPorte));
                }
            }
            this->nbPortesOuvertes= this->nbPortes;
        }
        else{
            this->position++;
        }
    }
    pthread_mutex_unlock(&mutex);

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
                if(s->emetteur()->getClasse()=="Station"){
                    for(int i= 0; i<this->nbPortes && this->nbPortesOuvertes>=0; i++)
                    {
                        if(this->sens=Rame::Aller)
                          this->portesGauche.at(i)->addSignal(new Signals(this, Signals::FermerPorte));
                        else
                          this->portesDroite.at(i)->addSignal(new Signals(this, Signals::FermerPorte));

                    }
                }
                else{
                    qDebug() << "Rame "<< this->numRame <<" \t > envoi Signals::EstPasse a "<< s->emetteur()->getClasse();
                    s->emetteur()->addSignal(new Signals(this, Signals::EstPasse));
                    this->position++;
                }
           }
           break;
        case Signals::PorteFermee:
        {
            this->nbPortesOuvertes--;
            if(this->nbPortesOuvertes==0){
                qDebug() << "Rame "<< this->numRame <<" \t portes fermees - Depart";
                qDebug() << "Rame "<< this->numRame <<" \t > envoi Signals::EstPasse a "<< s->emetteur()->getClasse();
                s->emetteur()->addSignal(new Signals(this, Signals::EstPasse));
                this->position++;
            }
       }
       break;
        }
    }
}

int Rame::getPosition(){    return this->position;
}
void Rame::setPosition(int i){
     this->position = i;
}

int Rame::getNumRame(){
    return this->numRame;
}
