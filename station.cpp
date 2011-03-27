#include "station.h"
#include <QDebug>

Station::Station(QString nom,Station::Type t)
{
    this->typeStation = t;
    this->nom=nom;
}

void Station::run()
{
    for(;;){}
}

void Station::createSignal()
{
    Signals * s;
    while(this->listSignals.size())
    {
        s = this->listSignals.takeFirst();
        switch(s->type())
        {
            case Signals::Demande:
            {
                if(!this->estVert())
                {
                    s->emetteur()->addSignal(new Signals(this,Signals::Arret));
                    sleep(5);
                    this->passerVert();
                    s->emetteur()->addSignal(new Signals(this,Signals::Passe));
                }
            }
            break;
            case Signals::EstPasse:
            {
                usleep(500000);
                this->passerRouge();
            }
            break;
        }
    }
}

void Station::afficher(QPainter * painter, int x, int y, int wElement, int hElement){
    painter->fillRect(x-wElement,y-hElement,wElement, hElement, QBrush(QColor(0,0,255)));
    painter->translate(x + wElement/2, y-(2*hElement));
    painter->rotate(-45);
    QFont font(QString("Helvetica"));
   font.setBold(true);
   font.setPixelSize(16);
   painter->setFont(font);
    painter->drawText(0, 0, this->nom);
    painter->rotate(+45);
    painter->translate(-x - wElement/2, -(y-(2*hElement)));
}

