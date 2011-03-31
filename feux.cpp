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

Feux::~Feux()
{
    delete ligne;
}

int Feux::nombreFeux=0;
Feux::Feux(): PointSynchronisation()
{
}

Feux::Feux(Ligne * ligne): PointSynchronisation()
{
    this->ligne = ligne;

    Feux::nombreFeux++;
    this->numPS= Feux::nombreFeux;
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
                if(this->suivant == NULL)
                    qDebug("feu suivnat null");
                if(!this->estVert())
                {
                    qDebug()<< this->suivant->getClasse();
                    if(this->suivant!= NULL){
                        qDebug()<<this->suivant->getDerniereRame()<<"-"<<this->derniereRame;
                        if(this->suivant->getDerniereRame()!=this->derniereRame){

                            qDebug() << "Feu "<< this->numPS << "\t rouge.";
                            s->emetteur()->addSignal(new Signals(this,Signals::Arret));
                        }
                        else{
                            this->passerVert();
                            s->emetteur()->addSignal(new Signals(this,Signals::Passe));
                        }
                    }
                    else{
                        qDebug() << "Feu "<< this->numPS << "\t rouge.";
                        s->emetteur()->addSignal(new Signals(this,Signals::Arret));
                    }
                }
                else{
                    qDebug() << "Feu "<< this->numPS << "\t deja vert.";
                    s->emetteur()->addSignal(new Signals(this,Signals::Passe));
                }

            }
            break;
            case Signals::EstPasse:
            {
                usleep(200000);
                qDebug() << "Feu "<< this->numPS << "\t Tram passe, passe rouge.";
                this->passerRouge();
                this->derniereRame = s->emetteur();
            }
            break;
        }
    }
}
