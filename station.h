#ifndef STATION_H
#define STATION_H
#include "pointsynchronisation.h"
#include <iostream>
#include <QPainter>
using namespace std;
class Station : public PointSynchronisation{
public:
    Station();
<<<<<<< HEAD
    void afficher(QPainter * painter, int x, int y);
    virtual QString getClasse(){ return QString("Station");}
=======
    void afficher(QPainter * painter, int x, int y, int wElement, int hElement);
>>>>>>> b17f6908637ec6e1f0fe3e1f19f2e443e40243ce
};


#endif // STATION_H
