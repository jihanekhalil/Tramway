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
    QList<Element *> aller;
    QList<Element *> retour;
    QList<Rame *> rames;
    int longueur;

public:
    Ligne();
    Ligne(int longueur);
    void afficher(QPainter * painter, int w, int h);
    void ajouterRame(Rame * rame);
    QList<Rame *> * getRames();
    void addElement(Element * e, int position);
    int getLongueur();
    Element * getElementAt(int i);
    Element * ElementExists(int i);
};

#endif // LIGNE_H
