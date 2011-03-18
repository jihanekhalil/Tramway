#include "pointsynchronisation.h"

PointSynchronisation::PointSynchronisation()
{
    this->vert=false;
}

void PointSynchronisation::afficher(QPainter * painter, int x, int y){


}

void PointSynchronisation::passerVert(){
    this->vert=true;
}

void PointSynchronisation::passerRouge(){
    this->vert=false;
}
bool PointSynchronisation::estVert(){
     return this->vert;
}
