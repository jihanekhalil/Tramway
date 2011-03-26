#ifndef STATION_H
#define STATION_H
#include "pointsynchronisation.h"
#include <iostream>
#include <QPainter>

class Station : public PointSynchronisation{
public:
    enum Type
    {
        Terminus,
        Intermediaire
    };

    Station(Station::Type);
    void afficher(QPainter * painter, int x, int y, int, int);
    virtual QString getClasse(){ return QString("Station");}
    void run();
    void createSignal();

private:
    Type typeStation;
};


#endif // STATION_H
