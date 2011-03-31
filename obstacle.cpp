#include "obstacle.h"
#include <QDebug>
Obstacle::Obstacle()
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::afficher(QPainter *painter, int x, int y, int w, int h){
    QPainterPath obstacle;
    obstacle.addEllipse(x, y, w, h);


    painter->drawPath(obstacle);
    painter->fillPath(obstacle, QBrush(QColor(255,0,0)));

}

Obstacle::Obstacle(QList<Element *> *sens, int position){
    this->sens = sens;
    this->position = position;

    sleep(10);
    qDebug()<<"bla";
    this->sens->replace(position, new Element());;
    delete(this);
}
