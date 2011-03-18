#include "ligne.h"
#include "feux.h"

Ligne::Ligne()
{
}
Ligne::Ligne(int longueur)
{
    this->longueur=longueur;

    for(int i=0; i<longueur;i++)
        this->ligne.push_back(new Element());

    Feux* e1 = new Feux();
    Feux* e2 = new Feux();
    Feux* e3 = new Feux();
    Feux* e4 = new Feux();
    Feux* e5 = new Feux();

    this->ligne[3] = e1;
    this->ligne[13] = e2;
    this->ligne[18] = e3;
    this->ligne[22] = e4;
    this->ligne[30] = e5;

    e1->passerVert();
    e5->passerVert();
    e3->passerVert();
}

Element * Ligne::getElementAt(int i){
    return this->ligne.at(i);
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
