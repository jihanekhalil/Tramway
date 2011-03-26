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
    Feux* e2 = new Feux();
    Feux* e3 = new Feux();    
    e1->start();
    e2->start();
    e3->start();
    e1->passerRouge();
    e2->passerRouge();
    e3->passerRouge();

    //STATIONS
    Station * s1 = new Station(Station::Intermediaire);
    s1->start();
    s1->passerRouge();

    //POSITIONNEMENT SUR LA LIGNE
    this->ligne[3] = e1;
    this->ligne[13] = s1;
    this->ligne[22] = e2;
    this->ligne[30] = e3;

}

Element * Ligne::getElementAt(int i)
{
    return this->ligne.at(i);
}

Element * Ligne::ElementExists(int i)
{
    for(int j=0; j<VISION; j++)
    {
        Element * e = this->ligne[i+j];
        Feux * f = dynamic_cast<Feux *>(e);

        qDebug() << "test : " << f->getClasse();
    }
}

void Ligne::afficher(QPainter * painter){
    // coordonnes d'origine du trait
    int xOrigine = 20;
    int yOrigine = 20;

    //taille dun element.
    int tailleElement= 5;

    // ligne
    painter->fillRect(QRectF(QPointF(xOrigine,yOrigine), QPointF(xOrigine+(this->longueur*tailleElement),yOrigine+3)), QBrush(QColor(0,0, 200)));

    int i = 0;
    foreach(Element * e, ligne){
        e->afficher(painter, xOrigine + (i * tailleElement) , yOrigine);
        i++;
    }

    foreach(Rame * r, this->rames)
    {
        r->afficher(painter, xOrigine + tailleElement*r->getPosition(), yOrigine);
    }

}

void Ligne::ajouterRame(Rame *rame){
    this->rames.push_back(rame);
}

QList<Rame *> * Ligne::getRames(){
    return &this->rames;
}

int Ligne::getLongueur(){
    return this->longueur;
}
