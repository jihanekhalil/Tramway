#ifndef FEUX_H
#define FEUX_H
#include "pointsynchronisation.h"
#include <iostream>
#include "thread.h"
#include "ligne.h"
using namespace std;
class Feux : public PointSynchronisation, Thread{
    Ligne * ligne;
    int position;
    Feux * suivant;
public:
    Feux();
    Feux(Ligne * ligne, Feux * suivant, int position);
 void run();
    virtual void afficher(QPainter * painter, int x, int y);
    int getPotision();
};

#endif // FEUX_H
