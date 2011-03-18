#ifndef POINTSYNCHRONISATION_H
#define POINTSYNCHRONISATION_H

#include <iostream>
#include <QPainter>
#include "element.h"
using namespace std;
class PointSynchronisation: public Element
{
        bool vert;
public:
    PointSynchronisation();
    virtual void afficher(QPainter * painter, int x, int y);
    bool estVert();
    void passerRouge();
    void passerVert();
};

#endif // POINTSYNCHRONISATION_H
