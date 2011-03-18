#include "rame.h"

#include <QList>
#include <QDebug>


void Rame::run()
{
    this->position=0;
    QList<Rame *> parcours = this->troncon->getParcours();
    parcours[0] = this;
    int i=0;
    foreach(Rame * rame, parcours ){
        if(i>0){
            rame = this;
        }
        //rame->position;
        i++;
    }
}
Rame::Rame(): Thread()
{
    Troncon * tr = new Troncon(20);
    this->troncon= tr;
}
void Rame::afficher(QPainter * painter, int x, int y)
{
    painter->fillRect(x, y, 10,3,QBrush(QColor(155,155,155)));
}

