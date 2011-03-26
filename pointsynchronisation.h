#ifndef POINTSYNCHRONISATION_H
#define POINTSYNCHRONISATION_H

#include <iostream>
#include <QPainter>
#include "element.h"
using namespace std;
class PointSynchronisation: public Element
{
protected:

        bool vert;
        int numPS;
public:
        static int nombrePS;
    PointSynchronisation();
    virtual void afficher(QPainter * painter, int x, int y, int , int);
    bool estVert();
    void passerRouge();
    void passerVert();
    int getNum();

};

#endif // POINTSYNCHRONISATION_H
