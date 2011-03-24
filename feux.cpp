#include "feux.h"
#include "ligne.h"
void Feux::run()
{

}

Feux::Feux(): Thread()
{
}

Feux::Feux(Ligne * ligne, Feux * suivant, int position): Thread()
{
    this->ligne = ligne;
    this->suivant=suivant;
    this->position=position;
}

void Feux::afficher(QPainter * painter, int x, int y, int wElement, int hElement){
   QPainterPath feu;
   feu.addEllipse(x, y-2*hElement, wElement, wElement);
   painter->drawPath(feu);
   if(this->estVert())
       painter->fillPath(feu, QBrush(QColor(0,255,0)));
   else
       painter->fillPath(feu, QBrush(QColor(255,0,0)));

}
