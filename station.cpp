#include "station.h"

Station::Station()
{
}


void Station::afficher(QPainter * painter, int x, int y, int wElement, int hElement){
    painter->fillRect(x,y,10, 5, QBrush(QColor(0,0,255)));
}
