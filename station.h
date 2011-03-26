#ifndef STATION_H
#define STATION_H
#include "pointsynchronisation.h"
#include <iostream>
#include <QPainter>
#include <QString>
using namespace std;
class Station : public PointSynchronisation{
public:
    Station();
    Station(QString);
    void afficher(QPainter * painter, int x, int y, int, int);
    virtual QString getClasse(){ return QString("Station");}
private:

    QString nom;
};


#endif // STATION_H
