#ifndef RAME_H
#define RAME_H
#include <QObject>
class Ligne;
#include "ligne.h"
#include "gestionsignal.h"
#include <QPainter>
#include "porte.h"
#include "pointsynchronisation.h"

class Rame: public GestionSignal
{    
public:
    Rame();
    Rame(Ligne * ligne);
    void run();
<<<<<<< HEAD
    void detectionPointSynchronisation();
    void afficher(QPainter * painter, int x, int y);
=======
    void afficher(QPainter * painter, int x, int y, int wElement,int hElement );
>>>>>>> b17f6908637ec6e1f0fe3e1f19f2e443e40243ce
    void avancer();
    int getPosition();
    void setPosition(int p);

private:
    Ligne* ligne;
    int position;
    QList<Porte *> portesDroite;
    QList<Porte *> portesGauche;

    void createSignal();
};

#endif // RAME_H
