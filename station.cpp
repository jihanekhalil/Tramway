#include "station.h"
#include <QDebug>

Station::Station(Station::Type t)
{
    this->typeStation = t;
}

void Station::afficher(QPainter * painter, int x, int y){
    painter->fillRect(x,y,10, 5, QBrush(QColor(255,215,0)));
}

void Station::run()
{
    for(;;)
        sleep(1);
}

void Station::createSignal()
{
    while(this->listSignals.size())
    {
        Signals * s = this->listSignals.takeFirst();
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
