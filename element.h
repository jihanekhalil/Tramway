#ifndef ELEMENT_H
#define ELEMENT_H
#include <QPainter>
#include <iostream>
using namespace std;
class Element
{
public:
    Element();
    virtual void afficher(QPainter * painter, int x, int y);
};

#endif // ELEMENT_H
