#include "station.h"
#include <QDebug>

int Station::nombreStations=0;

Station::Station(QString nom,Station::Type t):PointSynchronisation()
{
    this->typeStation = t;
    this->nom=nom;
    Station::nombreStations++;
    this->numPS= Station::nombreStations;
}

void Station::run()
{
    qDebug() << "Station run";
    for(;;){
        sleep(1);
    }
}

void Station::createSignal()
{
    while(this->listSignals.size())
    {
        Signals *s = this->listSignals.takeFirst();
        switch(s->type())
        {
            case Signals::Demande:
            {
                if(!this->estVert())
                {
                    qDebug() << "Station "<< this->numPS<< " \t signal Signals::Demande recu";
                    s->emetteur()->addSignal(new Signals(this,Signals::Arret));
                    sleep(5);
                    this->passerVert();
                    s->emetteur()->addSignal(new Signals(this,Signals::Passe));
                }
            }
            break;
            case Signals::EstPasse:
            {
                qDebug()<< "Message estPasse recu par Station";
                this->passerRouge();
                if(this->getPrecedent() != NULL)
                    this->getPrecedent()->passerVert();
                this->derniereRame = s->emetteur();                
            }
            break;
        }
    }
}

void Station::afficher(QPainter * painter, int x, int y, int wElement, int hElement, bool affNom){

    if(affNom){
    //    x-=wElement;
    }

    if(this->estVert())
        painter->setPen(QColor(0,255,0));
    else
        painter->setPen(QColor(255,0,0));
    if(affNom)
        painter->drawLine(x-wElement-1, y-hElement, x-1-wElement, y);
    else
        painter->drawLine(x, y, x, y-hElement);
    painter->setPen(QColor(0,0,0));

    painter->fillRect(x-wElement,y-hElement,wElement, hElement, QBrush(QColor(0,0,255)));
    if(affNom==true){
        painter->translate(x, y-(2*hElement));
        painter->rotate(-45);
        QFont font(QString("Helvetica"));
        font.setBold(true);
        font.setPixelSize(16);
        painter->setFont(font);
        painter->drawText(0, 0, this->nom);
        painter->rotate(+45);
        painter->translate(-x, -(y-(2*hElement)));
    }
}

QString Station::getNom(){
    return this->nom;
}

