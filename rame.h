#ifndef RAME_H
#define RAME_H
#include <QObject>
class Ligne;
#include "ligne.h"
#include "thread.h"
#include <QPainter>
#include "porte.h"

class Rame: public Thread
{
    Ligne* ligne;
    int position;
    QList<Porte *> portesDroite;
    QList<Porte *> portesGauche;
public:
    Rame();
    Rame(Ligne * ligne);
    void run();
    void afficher(QPainter * painter, int x, int y, int wElement,int hElement );
    void avancer();
    int getPosition();
    void setPosition(int p);


};

#endif // RAME_H
