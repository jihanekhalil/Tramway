#ifndef LIGNE_H
#define LIGNE_H
#include <QList>
#include <iostream>
#include "troncon.h"
#include <QPainter>
using namespace std;
class Ligne
{
    QList<Troncon> ligne;

public:
    Ligne();
    void ajouterTroncon(Troncon * t);
    void afficher(QPainter * painter);
};

#endif // LIGNE_H
