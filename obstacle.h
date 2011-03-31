#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "element.h"
#include <QPainter>
class Obstacle: public Element
{
public:
    Obstacle();
    void afficher(QPainter *painter, int x, int y, int, int);
    QString getClasse(){return QString("Obstacle");}
};

#endif // OBSTACLE_H
