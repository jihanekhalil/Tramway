#ifndef LIGNE_H
#define LIGNE_H
#include <QList>
#include <iostream>
#include "troncon.h"
using namespace std;
class Ligne
{
    QList<Troncon> ligne;

public:
    Ligne();
    void ajouterTroncon(Troncon * t);
    void afficher();
};

#endif // LIGNE_H
