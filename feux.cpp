#include "feux.h"

Feux::Feux()
{
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

