#include "ligne.h"
#include "feux.h"
#include <QDebug>
<<<<<<< HEAD

#define VISION 3

=======
>>>>>>> b17f6908637ec6e1f0fe3e1f19f2e443e40243ce
Ligne::Ligne()
{
}
Ligne::Ligne(int longueur)
{
    this->longueur=longueur;

    for(int i=0; i<longueur;i++){
        this->aller.push_back(new Element());
        this->retour.push_back(new Element());
    }

    Feux* e1 = new Feux();
    Feux* e2 = new Feux();
    Feux* e3 = new Feux();
    Feux* e4 = new Feux();
    Feux* e5 = new Feux();
<<<<<<< HEAD

    e1->start();
    e2->start();
    e3->start();
    e4->start();
    e5->start();

    this->ligne[3] = e1;
    this->ligne[13] = e2;
    this->ligne[18] = e3;
    this->ligne[22] = e4;
    this->ligne[30] = e5;
=======
    this->addElement(e1,3);
    this->addElement(e2,13);
    this->addElement(e3,18);
    this->addElement(e4,22);
    this->addElement(e5,33);
>>>>>>> b17f6908637ec6e1f0fe3e1f19f2e443e40243ce

    e1->passerVert();
    e2->passerVert();
    e5->passerVert();
    e3->passerVert();
}

<<<<<<< HEAD
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
=======
Element * Ligne::getElementAt(int i){
    return this->aller.at(i);
}

void Ligne::afficher(QPainter * painter, int w, int h){

>>>>>>> b17f6908637ec6e1f0fe3e1f19f2e443e40243ce
    // coordonnes d'origine du trait
    int xOrigine = 0.02 * w;
    int yOrigine = 0.2 * h;

    //taille dun element.
    int wElement= (w- (xOrigine *2))/this->longueur;
    int hElement= 6;

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

    foreach(Rame * r, this->rames)
    {
        r->afficher(painter, xOrigine + wElement*r->getPosition(), yOrigine, wElement, hElement );
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
void Ligne::addElement(Element *e, int position){
    this->aller[position] = e;
    //Element e2= new Element(e);
    this->retour[position] =  e;
}
