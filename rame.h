#ifndef RAME_H
#define RAME_H
#include <QObject>
class Troncon;
#include "troncon.h"
#include "thread.h"
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


};

#endif // RAME_H
