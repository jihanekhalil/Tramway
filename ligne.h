#ifndef LIGNE_H
#define LIGNE_H
class Rame;
#include <QList>
#include <iostream>
#include "element.h"
#include "rame.h"
#include <QPainter>
using namespace std;
class Ligne
{
    QList<Element *> ligne;
    QList<Rame *> rames;
    int longueur;

public:
    Ligne();
    Ligne(int longueur);
    void afficher(QPainter * painter);
    void ajouterRame(Rame * rame);
    QList<Rame *> * getRames();
    int getLongueur();
    Element * getElementAt(int i);
};

#endif // LIGNE_H
