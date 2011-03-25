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
    void surveiller();
    virtual void afficher(QPainter * painter, int x, int y);
    int getPosition();
    virtual QString getClasse(){ return QString("Feu");}
    void createSignal();

private:
    Ligne * ligne;
    int position;
    Feux * suivant;
};

#endif // FEUX_H
