#ifndef ELEMENT_H
#define ELEMENT_H
#include <QPainter>
#include <iostream>
using namespace std;
class Element
{
public:
    Element();
    Element (const Element &);
    virtual void afficher(QPainter * painter, int x, int y, int wElement, int hElement);
};

#endif // ELEMENT_H
