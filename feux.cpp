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

void Feux::afficher(QPainter * painter, int x, int y, int wElement, int hElement){
   QPainterPath feu;
   QVector<QPointF> points;
   points.push_back(QPointF((qreal) x, (qreal) y+hElement));
   points.push_back(QPointF((qreal) x-(wElement/4), (qreal) y+(2*hElement)));
   points.push_back(QPointF((qreal) x+(wElement/4), (qreal) y+(2*hElement)));
   feu.addPolygon(QPolygonF(points));
  // feu.addEllipse(x, y-2*hElement, wElement, wElement);
   painter->drawPath(feu);
   if(this->estVert())
       painter->fillPath(feu, QBrush(QColor(0,255,0)));
   else
       painter->fillPath(feu, QBrush(QColor(255,0,0)));

}


bool Feux::voieLibre(){
    QList<Rame *> * rames = this->ligne->getRames();
    /*
    if(suivant!=NULL){
        for(int i = position; i<suivant->getPosition(); i++){
            for(int j = 0 ; j<rames->at(j); j++){

            }
        }
    }*/
}

int Feux::getPosition(){
    return this->position;
}

void Feux::createSignal()
{
    qDebug() << "Feu "<< this->numPS << "\t create sig " << this->listSignals.size();
    while(this->listSignals.size())
    {
        Signals * s = this->listSignals.takeFirst();
        switch(s->type())
        {
            case Signals::Demande:
            {
                if(!this->estVert())
                {
                    qDebug() << "Feu "<< this->numPS << "\t rouge.";
                    s->emetteur()->addSignal(new Signals(this,Signals::Arret));
                    sleep(2);
                    this->passerVert();
                    s->emetteur()->addSignal(new Signals(this,Signals::Passe));
                }
                else{
                    qDebug() << "Feu "<< this->numPS << "\t deja vert.";
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
