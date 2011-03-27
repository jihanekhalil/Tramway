
#include "pointsynchronisation.h"
#include <QDebug>

PointSynchronisation::PointSynchronisation()
{
    this->vert=true;
}

void PointSynchronisation::afficher(QPainter * painter, int x, int y, int x1, int x2){


}

void PointSynchronisation::passerVert(){
    qDebug() << this->getClasse() << " " << this->numPS << "\tpasse Vert.";
    this->vert=true;
}

void PointSynchronisation::passerRouge(){
    qDebug() << this->getClasse() << " " << this->numPS << "\tpasse Rouge.";
    this->vert=false;
}
bool PointSynchronisation::estVert(){
     return this->vert;
}
int PointSynchronisation::getNum(){
    return this->numPS;
}
