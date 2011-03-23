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
