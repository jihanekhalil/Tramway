#ifndef RAME_H
#define RAME_H
#include <QObject>
class Troncon;
#include "troncon.h"
#include "thread.h"
#include <QPainter>
#include "porte.h"

class Rame: public Thread
{
    Troncon* troncon;
    int position;
    QList<Porte *> portesDroite;
    QList<Porte *> portesGauche;
public:
    Rame();
    void run();
    void afficher(QPainter * painter, int x, int y);


};

#endif // RAME_H
