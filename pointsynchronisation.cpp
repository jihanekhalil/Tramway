#include "pointsynchronisation.h"

PointSynchronisation::PointSynchronisation()
{
}

void PointSynchronisation::afficher(QPainter * painter, int x, int y){
    cout << "P";

}

void Feux::passerVert(){
    this->vert=true;
}

void Feux::passerRouge(){
    this->vert=false;
}
bool Feux::estVert(){
     return this->vert;
}
