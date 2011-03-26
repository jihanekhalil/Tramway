#include "station.h"

Station::Station()
{
}
Station::Station(QString nom)
{
    this->nom=nom;
}


void Station::afficher(QPainter * painter, int x, int y, int wElement, int hElement){
    painter->fillRect(x,y-hElement,wElement, hElement, QBrush(QColor(0,0,255)));
    painter->translate(x + wElement/2, y-(2*hElement));
    painter->rotate(-30);
    QFont font(QString("Helvetica"));
   font.setBold(true);
   font.setPixelSize(16);
   painter->setFont(font);
    painter->drawText(0, 0, this->nom);
    painter->rotate(+30);
    painter->translate(-x - wElement/2, -(y-(2*hElement)));

}

