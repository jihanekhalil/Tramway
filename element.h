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
    virtual void afficher(QPainter * painter, int x, int y);
    virtual void createSignal(){}
};

#endif // ELEMENT_H
