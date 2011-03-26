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
    void afficher(QPainter * painter, int x, int y);
    void avancer();
    int getPosition();

private:
    Ligne* ligne;
    int position;
    QList<Porte *> portesDroite;
    QList<Porte *> portesGauche;

    void createSignal();
};

#endif // RAME_H
