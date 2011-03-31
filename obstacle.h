#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "element.h"
#include <QPainter>
#include "element.h"
class Obstacle: public Element
{
public:
    Obstacle();
    ~Obstacle();
    Obstacle(QList<Element *> * sens, int position);
    void afficher(QPainter *painter, int x, int y, int, int);
    QString getClasse(){return QString("Obstacle");}

private:
    QList<Element *> * sens;
    int position;
};

#endif // OBSTACLE_H
