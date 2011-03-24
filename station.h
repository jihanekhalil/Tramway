#ifndef STATION_H
#define STATION_H
#include "pointsynchronisation.h"
#include <iostream>
#include <QPainter>
using namespace std;
class Station : public PointSynchronisation{
public:
    Station();
    void afficher(QPainter * painter, int x, int y, int wElement, int hElement);
};


#endif // STATION_H
