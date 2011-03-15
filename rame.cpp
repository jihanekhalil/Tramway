#include "rame.h"

#include <QList>
#include <QDebug>


void Rame::run()
{
    this->position=0;
    QList<Rame *> parcours = this->troncon->getParcours();
    parcours[0] = this;
    for(int i = 1; i<parcours.length();i++){
    //for(QList<Rame *>::iterator it = parcours.begin()+1; it!=parcours.end(); it++ ){
        qDebug() <<"bla";
    }
}
Rame::Rame(): Thread()
{
    Troncon * tr = new Troncon(20);
    this->troncon= tr;
}
void Rame::afficher(QPainter * painter, int x, int y)
{
    cout << "t";
}

