#include "ligne.h"
#include "feux.h"
#include "station.h"
#include <QDebug>

#define VISION 3

Ligne::Ligne()
{
}
Ligne::Ligne(int longueur)
{
    this->longueur=longueur;

    for(int i=0; i<longueur;i++)
        this->ligne.push_back(new Element());

    //FEUX
    Feux* e1 = new Feux();
//    Feux* e2 = new Feux();
//    Feux* e3 = new Feux();
//    Feux* e4 = new Feux();
//    Feux* e5 = new Feux();
    Station* e6 = new Station(QString("Carmes"),Station::Intermediaire);
//    Station* e7 = new Station(QString("Jean Jaures"),Station::Intermediaire);
//    Station* e8 = new Station(QString("Rangueil"),Station::Intermediaire);
    e1->start();
//    e2->start();
//    e3->start();
//    e4->start();

//    e5->start();
    e6->start();
    e6->passerRouge();
//    e7->start();
//    e7->passerRouge();
//    e8->start();
//    e8->passerRouge();

    this->ligne[3] = e1;
//    this->ligne[13] = e2;
//    this->ligne[18] = e3;
//    this->ligne[22] = e4;
//    this->ligne[30] = e5;

//    this->ligne[20] = e7;

//    this->ligne[10] = e8;

    this->ligne[40] = e6;
    //e1->passerRouge();
    //e2->passerRouge();
    //e5->passerRouge();
    //e3->passerRouge();

}

Element * Ligne::getElementAt(int i)
{
    return this->ligne.at(i);
}

Element * Ligne::ElementExists(int i)
{
    Element * e;
    Feux * f;
    for(int j=0; j<VISION; j++)
    {
         e = this->ligne[i+j];
         f = dynamic_cast<Feux *>(e);

        qDebug() << "test : " << f->getClasse();
    }
}

void Ligne::afficher(QPainter * painter, int w, int h){

    // coordonnes d'origine du trait
    int xOrigine = 0.02 * w;
    int yOrigine = 0.3 * h;

    //taille dun element.
    int wElement= (w- (xOrigine *2))/this->longueur;
    int hElement= 6;
    painter->fillRect(QRectF(QPointF(xOrigine,yOrigine), QPointF(xOrigine+(this->longueur*wElement),yOrigine+hElement)), QBrush(QColor(150,150, 150)));

    for(int i = 0; i<ligne.size(); i++){
        ligne.at(i)->afficher(painter, xOrigine + (i * wElement) , yOrigine, wElement, hElement);
        i++;
    }
/*
    // aller
    painter->fillRect(QRectF(QPointF(xOrigine,yOrigine), QPointF(xOrigine+(this->longueur*wElement),yOrigine+hElement)), QBrush(QColor(0,0, 0)));

    int i = 0;
    foreach(Element * e, aller){
        e->afficher(painter, xOrigine + (i * wElement) , yOrigine, wElement, hElement);
        i++;
    }


    // retour
    painter->fillRect(QRectF(QPointF(xOrigine,yOrigine*2), QPointF(xOrigine+(this->longueur*wElement),yOrigine*2+hElement)), QBrush(QColor(0,0, 0)));

     i = 0;
    foreach(Element * e, aller){
        e->afficher(painter, xOrigine + (i * wElement) , yOrigine*2+(hElement*3), wElement, hElement);
        i++;
    }
    bla
*/
    Rame * r;
    for(int i=0; i<rames.size(); i++)
    {
        r=rames.at(i);
        r->afficher(painter, xOrigine + wElement*r->getPosition(), yOrigine, wElement, hElement );
    }

}


void Ligne::ajouterRame(Rame *rame){
    this->rames.push_back(rame);
}

QList<Rame *> * Ligne::getRames(){
    return &this->rames;
}

Rame * Ligne::getRameAt(int i){
    return this->rames.at(i);
}

int Ligne::getLongueur(){
    return this->longueur;
}
int Ligne::getNbRames(){
    return this->rames.size();
}
