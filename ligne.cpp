#include "ligne.h"
#include "feux.h"
#include "station.h"
#include <QDebug>
#include "obstacle.h"

#define VISION 3

Ligne::Ligne()
{}

Ligne::~Ligne()
{
    for(int i=0; i<this->aller.size(); i++)
        delete this->aller.at(i);
    for(int i=0; i<this->retour.size(); i++)
        delete this->retour.at(i);
    for(int i=0; i<this->rames.size(); i++)
        delete this->rames.at(i);
    for(int i=0; i<this->listeElement.size(); i++)
        delete this->listeElement.at(i);
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
    this->aller[15] = e11;
    Feux* e12 = new Feux(this);
    e12->start();
    this->aller[25] = e12;
    Feux* e13 = new Feux(this);
    e13->start();
    this->aller[35] = e13;
    Feux* e14 = new Feux(this);
    e14->start();
    this->aller[45] = e14;
    Feux* e15 = new Feux(this);
    e15->start();
    this->aller[55] = e15;
    Feux* e16 = new Feux(this);
    e16->start();
    this->aller[65] = e16;
    Feux* e17 = new Feux(this);
    e17->start();
    this->aller[75] = e17;
    Feux* e18 = new Feux(this);
    e18->start();
    this->aller[85] = e18;


    //  STATIONS

    Station* e19 = new Station(QString("Borderouge"),Station::Terminus, this);
    e19->start();
    e19->passerRouge();
    this->aller[10] = e19;
    this->listeStation.push_back(e19);

    Station* e110 = new Station(QString("Compans"),Station::Intermediaire, this);
    e110->start();
    e110->passerRouge();
    this->aller[30] = e110;
    this->listeStation.push_back(e110);


    Station* e111 = new Station(QString("Jeanne d Arc"),Station::Intermediaire, this);
    e111->start();
    e111->passerRouge();
    this->aller[50] = e111;
    this->listeStation.push_back(e111);


    Station* e112 = new Station(QString("Carmes"),Station::Intermediaire, this);
    e112->start();
    e112->passerRouge();
    this->aller[70] = e112;
    this->listeStation.push_back(e112);

    Station* e113 = new Station(QString("Ramonville"),Station::Terminus, this);
    e113->start();
    e113->passerRouge();
    this->aller[95] = e113;
    this->listeStation.push_back(e113);


    //RETOUR

    Feux* e21 = new Feux(this);
    e21->start();
    this->retour[15] = e21;
    Feux* e22 = new Feux(this);
    e22->start();
    this->retour[25] = e22;
    Feux* e23 = new Feux(this);
    e23->start();
    this->retour[35] = e23;
    Feux* e24 = new Feux(this);
    e24->start();
    this->retour[45] = e24;
    Feux* e25 = new Feux(this);
    e25->start();
    this->retour[55] = e25;
    Feux* e26 = new Feux(this);
    e26->start();
    this->retour[65] = e26;
    Feux* e27 = new Feux(this);
    e27->start();
    this->retour[75] = e27;
    Feux* e28 = new Feux(this);
    e28->start();
    this->retour[85] = e28;


    //  STATIONS

    Station* e29 = new Station(QString("Borderouge"),Station::Terminus, this);
    e29->start();
    e29->passerRouge();
    this->retour[10] = e29;
    this->listeStation.push_back(e29);

    Station* e210 = new Station(QString("Compans"),Station::Intermediaire, this);
    e210->start();
    e210->passerRouge();
    this->retour[30] = e210;
    this->listeStation.push_back(e210);


    Station* e211 = new Station(QString("Jeanne d Arc"),Station::Intermediaire, this);
    e211->start();
    e211->passerRouge();
    this->retour[50] = e211;
    this->listeStation.push_back(e211);


    Station* e212 = new Station(QString("Carmes"),Station::Intermediaire, this);
    e212->start();
    e212->passerRouge();
    this->retour[70] = e212;
    this->listeStation.push_back(e212);

    Station* e213 = new Station(QString("Ramonville"),Station::Terminus, this);
    e213->start();
    e213->passerRouge();
    this->retour[95] = e213;
    this->listeStation.push_back(e213);



    e29->setSuivant(e19);
    e213->setSuivant(e113);



    this->listeElement.append(e11);
    this->listeElement.append(e19);
    this->listeElement.append(e21);
    this->listeElement.append(e29);

    this->updateListPS();

    for(int i = 0; i < this->listeStation.size(); i++){
        this->listeStation.at(i)->setPassagers();
    }
   // qDebug()<<"teeeeeest " <<e29->getSuivant()->getNum();
}

Element * Ligne::getElementAt(int i, bool aller)
{
    qDebug()<<"getElementAt"<< i << " - "<< aller;
    if(aller==true)
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
    int yOrigine = 200;

    //taille dun element.
    int wElement= (w- (xOrigine *2) )/this->longueur;
    int hElement= 12;

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
   // xOrigine+=wElement;
    // aller
    painter->fillRect(QRectF(QPointF(xOrigine,yOrigine), QPointF(xOrigine+(this->longueur*wElement),yOrigine+hElement)), QBrush(QColor(0,0, 0)));

    i = 0;
    foreach(Element * e, aller){
        if(e->getClasse()=="Station"){
            dynamic_cast<Station *>(e)->afficher(painter, xOrigine + (i * wElement) , yOrigine+(2*hElement), wElement, hElement,false);
        }
        else if(e->getClasse()=="Obstacle"){
            e->afficher(painter, xOrigine + (i * wElement) , yOrigine, wElement, hElement);
        }
        else
            e->afficher(painter, xOrigine + (i * wElement) , yOrigine-(2*hElement), wElement, hElement);
        i++;

    }


    for(int i=0; i<rames.size(); i++)
    {
        Rame * r=rames.at(i);
        if(r->sens==Rame::Aller)
            r->afficher(painter, xOrigine + wElement*r->getPosition(), yOrigine, wElement, hElement );
        else
            r->afficher(painter, xOrigine + (wElement *r->getPosition())+wElement, yOrigine/1.3, wElement, hElement );

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
    qDebug() << "updateListPS $$$$$";
    bool last=true;
    PointSynchronisation * suivant;
    for(int i=this->aller.size()-1; i>=0;i--){
        Element * e = this->aller.at(i);
        if(e->getClasse()=="Feu" || e->getClasse()=="Station"){
            PointSynchronisation * ps = dynamic_cast<PointSynchronisation *>(e);
            if(last){
                ps->setSuivant(NULL);
                last=false;
                qDebug()<< ps->getClasse() << " "<< ps->getNum() << "\tsuivant : NULL" ;
            }else{
                ps->setSuivant(suivant);
            }
            suivant = ps;
        }
    }
    last = true;
    for(int i=0; i<this->longueur;i++){
        Element * e = this->retour.at(i);
        if(e->getClasse()=="Feu" || e->getClasse()=="Station"){
            PointSynchronisation * ps = dynamic_cast<PointSynchronisation *>(e);
            if(last){
                ps->setSuivant(NULL);
                last=false;
                qDebug()<< ps->getClasse() << " "<< ps->getNum() << "\tsuivant : NULL" ;
            }else{
                ps->setSuivant(suivant);
                //qDebug()<< ps->getClasse() << " "<< ps->getNum() << "\tsuivant :"<< suivant->getClasse()<<" "<<suivant->getNum() ;
            }
            suivant = ps;
        }
    }
    qDebug() << "FIN updateListPS $$$$$";
}

QList<Element *> * Ligne::getListeElement()
{
    return &this->listeElement;
}


QList <Station *> * Ligne::getStations(){
    return &this->listeStation;
}

void Ligne::ajouterObstacle(){
    int position = rand()%this->longueur;
    Obstacle * o = new Obstacle(&this->aller, position);
     //while()
    this->aller[position] = o;


}
