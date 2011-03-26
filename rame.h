#ifndef RAME_H
#define RAME_H
#include <QObject>
class Ligne;
class Porte;
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

    void afficher(QPainter * painter, int x, int y, int, int);
    void avancer();
    int getPosition();
    void setPosition(int);
    static int nbRame;
    int getNumRame();
private:
    int nbPortesOuvertes;
    Ligne* ligne;
    int position;
    int numRame;
    int nbPortes;
    QList<Porte *> portesDroite;
    QList<Porte *> portesGauche;

    void createSignal();
};

#endif // RAME_H
