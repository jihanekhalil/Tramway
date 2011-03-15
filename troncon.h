#ifndef TRONCON_H
#define TRONCON_H
#include "pointsynchronisation.h"
#include <QObject>
#include <QList>
#include <QPainter>
#include <iostream>
#include "station.h"
#include "feux.h"

class Rame;
#include "rame.h"
using namespace std;
class Troncon
{
    int longueur;
    PointSynchronisation* p1;
    PointSynchronisation* p2;
    QList<Rame *> parcours;
public:
    Troncon();
    Troncon(int pLongueur);
    bool estFini(int position);

    QList<Rame *> getParcours();
    void setEtat(int position, Rame * rame);
    void afficher(QPainter * painter, int x, int y);
};

#endif // TRONCON_H
