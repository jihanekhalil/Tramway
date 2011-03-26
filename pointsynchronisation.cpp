#include "pointsynchronisation.h"
#include <QDebug>
int PointSynchronisation::nombrePS=0;

PointSynchronisation::PointSynchronisation()
{
    this->vert=true;
    PointSynchronisation::nombrePS++;
    this->numPS= PointSynchronisation::nombrePS;
}

void PointSynchronisation::afficher(QPainter * painter, int x, int y, int x1, int x2){


}

void PointSynchronisation::passerVert(){
    qDebug() << this->getClasse() << " " << this->nombrePS << "\t passe Vert.";
    this->vert=true;
}

void PointSynchronisation::passerRouge(){
    qDebug() << this->getClasse() << " " << this->nombrePS << "\t passe Rouge.";
    this->vert=false;
}
bool PointSynchronisation::estVert(){
     return this->vert;
}
int PointSynchronisation::getNum(){
    return this->numPS;
}
