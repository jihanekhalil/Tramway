#ifndef FEUX_H
#define FEUX_H
#include "pointsynchronisation.h"
#include <iostream>
#include "thread.h"
#include "ligne.h"
using namespace std;
class Feux : public PointSynchronisation{

public:
    Feux();
    Feux(Ligne * ligne, Feux * suivant, int position);
    void run();
    bool voieLibre();
    virtual void afficher(QPainter * painter, int x, int y, int, int);
    int getPosition();
    virtual QString getClasse(){ return QString("Fe");}
    void createSignal();

private:
    Ligne * ligne;
    int position;
    Feux * suivant;
};

#endif // FEUX_H
