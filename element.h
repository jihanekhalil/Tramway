#ifndef ELEMENT_H
#define ELEMENT_H
#include <QPainter>
#include <iostream>
#include "gestionsignal.h"

using namespace std;
class Element : public GestionSignal
{
public:
    Element();
<<<<<<< HEAD
    virtual void afficher(QPainter * painter, int x, int y);
    virtual void createSignal(){}
=======
    Element (const Element &);
    virtual void afficher(QPainter * painter, int x, int y, int wElement, int hElement);
>>>>>>> b17f6908637ec6e1f0fe3e1f19f2e443e40243ce
};

#endif // ELEMENT_H
