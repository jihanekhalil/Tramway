#include "feux.h"
#include "ligne.h"
#include <QDebug>

void Feux::run()
{
    for(;;)
    {
        sleep(1);
    }
}

Feux::Feux(): PointSynchronisation()
{
}

Feux::Feux(Ligne * ligne, Feux * suivant, int position): PointSynchronisation()
{
    this->ligne = ligne;
    this->suivant=suivant;
    this->position=position;
}

void Feux::afficher(QPainter * painter, int x, int y){
   QPainterPath feu;
   feu.addEllipse(x, y, 7, 7);
   painter->drawPath(feu);
   if(this->estVert())
       painter->fillPath(feu, QBrush(QColor(0,255,0)));
   else
       painter->fillPath(feu, QBrush(QColor(255,0,0)));

}

void Feux::surveiller(){
    for(int i = position; i<suivant->getPosition(); i++){
      //  this->ligne[i]
    }
}

int Feux::getPosition(){
    return this->position;
}

void Feux::createSignal()
{
    qDebug() << "create sig " << this->listSignals.size();
    while(this->listSignals.size())
    {
        Signals * s = this->listSignals.takeFirst();
        switch(s->type())
        {
            case Signals::Demande:
            {
                if(!this->estVert())
                {
                    qDebug("feu vert");
                    s->emetteur()->addSignal(new Signals(this,Signals::Arret));
                    sleep(5);
                    this->passerVert();
                    s->emetteur()->addSignal(new Signals(this,Signals::Passe));
                }
                else
                    qDebug("feu déjà vert");
            }
            break;
            case Signals::EstPasse:
            {
                sleep(2);
                this->passerRouge();
            }
            break;
        }
    }
}
