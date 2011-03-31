#include "obstacle.h"

Obstacle::Obstacle()
{
}

void Obstacle::afficher(QPainter *painter, int x, int y, int w, int h){
    QPainterPath obstacle;
    obstacle.addEllipse(x, y, w, h);


    painter->drawPath(obstacle);
    painter->fillPath(obstacle, QBrush(QColor(255,0,0)));

}

