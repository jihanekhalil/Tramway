#ifndef FEUX_H
#define FEUX_H
#include "pointsynchronisation.h"
#include <iostream>
using namespace std;
class Feux : public PointSynchronisation{

public:
    Feux();

    void afficher(QPainter * painter, int x, int y);
};

#endif // FEUX_H
