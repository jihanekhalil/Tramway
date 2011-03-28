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
        this->aller.push_back(new Element());

    for(int i=0; i<longueur;i++)
        this->retour.push_back(new Element());


    //ALLER

    //FEUX

    Feux* e11 = new Feux(this);

    e11->start();

    this->retour[5] = e11;


    //  STATIONS

   // Station* e16 = new Station(QString("Carmes"),Station::Terminus);
   // Station* e17 = new Station(QString("Jean Jaures"),Station::Intermediaire);
    Station* e19 = new Station(QString("Borderouge"),Station::Terminus);


  //  e16->start();
  //  e16->passerRouge();
  //   e17->start();
  //  e17->passerRouge();

    e19->start();
    e19->passerRouge();
    this->retour[25] = e19;
   // this->retour[15] = e17;

    //this->retour[5] = e16;


    //RETOUR

    //FEUX
    Feux* e21 = new Feux(this);

    e21->start();

    this->aller[5] = e21;


    //  STATIONS

   // Station* e26 = new Station(QString("Carmes"),Station::Terminus);
   // Station* e27 = new Station(QString("Jean Jaures"),Station::Intermediaire);
    Station* e29 = new Station(QString("Borderouge"),Station::Terminus);


 //   e26->start();
 //   e26->passerRouge();
 //    e27->start();
 //   e27->passerRouge();

    e29->start();
    e29->passerRouge();
    this->aller[25] = e29;
  //  this->aller[15] = e27;

    //this->aller[5] = e26;
       e29->setSuivant(e19);

    //   e16->setSuivant(e26);

    this->listeElement.append(e11);
    this->listeElement.append(e19);
    this->listeElement.append(e21);
    this->listeElement.append(e29);

    this->updateListPS();
}

Element * Ligne::getElementAt(int i, bool aller)
{
    if(aller)
        return this->aller.at(i);
    else
        return this->retour.at(i);
}

Element * Ligne::ElementExists(int i)
{
    Element * e;
    Feux * f;
    for(int j=0; j<VISION; j++)
    {
         //e = this->ligne[i+j];
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

    // retour
    painter->fillRect(QRectF(QPointF(xOrigine,yOrigine), QPointF(xOrigine+(this->longueur*wElement),yOrigine+hElement)), QBrush(QColor(0,0, 0)));


    int i = 0;
    foreach(Element * e, retour){
        if(e->getClasse()=="Station"){
            dynamic_cast<Station *>(e)->afficher(painter, xOrigine + (i * wElement) , yOrigine, wElement, hElement,true);
        }
        else
            e->afficher(painter, xOrigine + (i * wElement) , yOrigine, wElement, hElement);
        i++;

    }

    yOrigine*=1.3;

    // aller
    painter->fillRect(QRectF(QPointF(xOrigine,yOrigine), QPointF(xOrigine+(this->longueur*wElement),yOrigine+hElement)), QBrush(QColor(0,0, 0)));

    i = 0;
    foreach(Element * e, aller){
        if(e->getClasse()=="Station"){
            dynamic_cast<Station *>(e)->afficher(painter, xOrigine + (i * wElement) , yOrigine+(2*hElement), wElement, hElement,false);
        }
        else
            e->afficher(painter, xOrigine + (i * wElement) , yOrigine-(2*hElement), wElement, hElement);
        i++;

    }


    for(int i=0; i<rames.size(); i++)
    {
        Rame * r=rames.at(i);
        if(r->sens=Rame::Aller)
            r->afficher(painter, xOrigine + wElement*r->getPosition(), yOrigine, wElement, hElement );
        else
            r->afficher(painter, xOrigine/1.5 + wElement*r->getPosition(), yOrigine, wElement, hElement );

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

void Ligne::updateListPS(){
    //qDebug() << "updateListPS $$$$$";
    bool last=true;
    PointSynchronisation * suivant;
    for(int i=this->aller.size()-1; i>=0;i--){
        Element * e = this->retour.at(i);
        if(e->getClasse()=="Feu" || e->getClasse()=="Station"){
            PointSynchronisation * ps = dynamic_cast<PointSynchronisation *>(e);
            if(last){
                ps->setSuivant(NULL);
                last=false;
                //qDebug()<< ps->getClasse() << " "<< ps->getNum() << "\tsuivant : NULL" ;
            }else{
                ps->setSuivant(suivant);
                //qDebug()<< ps->getClasse() << " "<< ps->getNum() << "\tsuivant :"<< suivant->getClasse()<<" "<<suivant->getNum() ;
            }
            suivant = ps;
        }
    }
    for(int i=this->retour.size()-1; i>=0;i--){
        Element * e = this->retour.at(i);
        if(e->getClasse()=="Feu" || e->getClasse()=="Station"){
            PointSynchronisation * ps = dynamic_cast<PointSynchronisation *>(e);
            if(last){
                ps->setSuivant(NULL);
                last=false;
                //qDebug()<< ps->getClasse() << " "<< ps->getNum() << "\tsuivant : NULL" ;
            }else{
                ps->setSuivant(suivant);
                //qDebug()<< ps->getClasse() << " "<< ps->getNum() << "\tsuivant :"<< suivant->getClasse()<<" "<<suivant->getNum() ;
            }
            suivant = ps;
        }
    }
     //qDebug() << "FIN updateListPS $$$$$";
}

QList<Element *> * Ligne::getListeElement()
{
    return &this->listeElement;
}
