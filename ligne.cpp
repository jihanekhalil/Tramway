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
    for (int i = 0; i < this->aller.size(); i++)
        delete this->aller.at(i);
    for (int i = 0; i < this->retour.size(); i++)
        delete this->retour.at(i);
    for (int i = 0; i < this->rames.size(); i++)
        delete this->rames.at(i);
    for (int i = 0; i < this->listeElement.size(); i++)
        delete this->listeElement.at(i);
}

Ligne::Ligne(int longueur)
{
    this->longueur = longueur;

    for (int i = 0; i < longueur; i++)
        this->aller.push_back(new Element());

    for (int i = 0; i < longueur; i++)
        this->retour.push_back(new Element());


    //ALLER

    //FEUX
    Feux* f1 = new Feux(this);
    f1->start();
    this->aller[5] = f1;
    Feux* f2 = new Feux(this);
    f2->start();
    this->aller[15] = f2;
    Feux* f3 = new Feux(this);
    f3->start();
    this->aller[25] = f3;
    Feux* f4 = new Feux(this);
    f4->start();
    this->aller[35] = f4;
    Feux* f5 = new Feux(this);
    f5->start();
    this->aller[45] = f5;
    Feux* f6 = new Feux(this);
    f6->start();
    this->aller[55] = f6;
    Feux* f7 = new Feux(this);
    f7->start();
    this->aller[65] = f7;
    Feux* f8 = new Feux(this);
    f8->start();
    this->aller[75] = f8;
    Feux* f9 = new Feux(this);
    f9->start();
    this->aller[85] = f9;


    //  STATIONS
    Station* s1 = new Station(QString("Borderouge"), Station::Intermediaire, this);
    s1->start();
    s1->passerRouge();
    this->aller[10] = s1;
    this->listeStation.push_back(s1);

    Station* s2 = new Station(QString("Compans"), Station::Intermediaire, this);
    s2->start();
    s2->passerRouge();
    this->aller[30] = s2;
    this->listeStation.push_back(s2);


    Station* s3 = new Station(QString("Jeanne d Arc"), Station::Intermediaire, this);
    s3->start();
    s3->passerRouge();
    this->aller[50] = s3;
    this->listeStation.push_back(s3);

    Station* s4 = new Station(QString("Carmes"), Station::Intermediaire, this);
    s4->start();
    s4->passerRouge();
    this->aller[70] = s4;
    this->listeStation.push_back(s4);

    Station* s5 = new Station(QString("Ramonville"), Station::Terminus, this);
    s5->start();
    s5->passerRouge();
    this->aller[95] = s5;
    this->listeStation.push_back(s5);


    //RETOUR

    Feux* fr1 = new Feux(this);
    fr1->start();
    this->retour[15] = fr1;
    Feux* fr2 = new Feux(this);
    fr2->start();
    this->retour[25] = fr2;
    Feux* fr3 = new Feux(this);
    fr3->start();
    this->retour[35] = fr3;
    Feux* fr4 = new Feux(this);
    fr4->start();
    this->retour[45] = fr4;
    Feux* fr5 = new Feux(this);
    fr5->start();
    this->retour[55] = fr5;
    Feux* fr6 = new Feux(this);
    fr6->start();
    this->retour[65] = fr6;
    Feux* fr7 = new Feux(this);
    fr7->start();
    this->retour[75] = fr7;
    Feux* fr8 = new Feux(this);
    fr8->start();
    this->retour[85] = fr8;


    //  STATIONS


    Station* sr1 = new Station(QString("Borderouge"), Station::Terminus, this);
    sr1->start();
    sr1->passerRouge();
    this->retour[10] = sr1;
    this->listeStation.push_back(sr1);

    Station* sr2 = new Station(QString("Compans"), Station::Intermediaire, this);
    sr2->start();
    sr2->passerRouge();
    this->retour[30] = sr2;
    this->listeStation.push_back(sr2);

    Station* sr3 = new Station(QString("Jeanne d Arc"), Station::Intermediaire, this);
    sr3->start();
    sr3->passerRouge();
    this->retour[50] = sr3;
    this->listeStation.push_back(sr3);

    Station* sr4 = new Station(QString("Carmes"), Station::Intermediaire, this);
    sr4->start();
    sr4->passerRouge();
    this->retour[70] = sr4;
    this->listeStation.push_back(sr4);

    Station* sr5 = new Station(QString("Ramonville"), Station::Intermediaire, this);
    sr5->start();
    sr5->passerRouge();
    this->retour[95] = sr5;
    this->listeStation.push_back(sr5);

    sr1->setSuivant(s1);
    s5->setSuivant(sr5);

    sr5->setPrecedent(s5);
    s1->setPrecedent(sr1);

    this->listeElement.append(f1);
    this->listeElement.append(f2);
    this->listeElement.append(f3);
    this->listeElement.append(f4);
    this->listeElement.append(f5);
    this->listeElement.append(f6);
    this->listeElement.append(f7);
    this->listeElement.append(f8);
    this->listeElement.append(f9);

    this->listeElement.append(fr1);
    this->listeElement.append(fr2);
    this->listeElement.append(fr3);
    this->listeElement.append(fr4);
    this->listeElement.append(fr5);
    this->listeElement.append(fr6);
    this->listeElement.append(fr7);
    this->listeElement.append(fr8);

    this->listeElement.append(s1);
    this->listeElement.append(s2);
    this->listeElement.append(s3);
    this->listeElement.append(s4);
    this->listeElement.append(s5);

    this->listeElement.append(sr1);
    this->listeElement.append(sr2);
    this->listeElement.append(sr3);
    this->listeElement.append(sr4);
    this->listeElement.append(sr5);

    this->updateListPSsuivant();
    this->updateListPSprecedent();

    for (int i = 0; i < this->listeStation.size(); i++) {
        this->listeStation.at(i)->setPassagers();
    }

}

Element * Ligne::getElementAt(int i, bool aller)
{
    qDebug() << "getElementAt" << i << " - " << aller;
    if (aller == true)
        return this->aller.at(i);
    else
        return this->retour.at(i);
}

Element * Ligne::ElementExists(int i)
{
    Element * e;
    Feux * f;
    for (int j = 0; j < VISION; j++) {
        //e = this->ligne[i+j];
        f = dynamic_cast<Feux *>(e);

        qDebug() << "test : " << f->getClasse();
    }
}

void Ligne::afficher(QPainter * painter, int w, int h)
{

    QFont font(QString("Helvetica"));
    font.setBold(true);
    font.setPixelSize(35);
    painter->setFont(font);

    painter->setPen(QColor(0, 55, 166));
    painter->drawText(70, 40, this->listeStation.first()->getNom() + " / " + this->listeStation.last()->getNom());
    // coordonnes d'origine du trait
    int xOrigine = 0.02 * w;
    int yOrigine = 200;

    //taille dun element.
    int wElement = (w - (xOrigine * 2)) / this->longueur;
    int hElement = 12;

    // retour
    painter->fillRect(QRectF(QPointF(xOrigine - wElement, yOrigine), QPointF(xOrigine + (this->longueur*wElement) - wElement, yOrigine + hElement)), QBrush(QColor(115, 115, 115)));


    int i = 0;
    foreach(Element * e, retour) {
        if (e->getClasse() == "Station") {
            dynamic_cast<Station *>(e)->afficher(painter, xOrigine + (i * wElement) , yOrigine, wElement, hElement, true);
        } else
            e->afficher(painter, xOrigine + (i * wElement) , yOrigine - (2*hElement), wElement, hElement);
        i++;

    }

    yOrigine += wElement;
    // xOrigine+=wElement;
    // aller
    painter->fillRect(QRectF(QPointF(xOrigine, yOrigine), QPointF(xOrigine + (this->longueur*wElement), yOrigine + hElement)), QBrush(QColor(115, 115, 115)));

    i = 0;
    foreach(Element * e, aller) {
        if (e->getClasse() == "Station") {
            dynamic_cast<Station *>(e)->afficher(painter, xOrigine + (i * wElement) , yOrigine + (2*hElement), wElement, hElement, false);
        } else if (e->getClasse() == "Obstacle") {
            e->afficher(painter, xOrigine + (i * wElement) , yOrigine, wElement, hElement);
        } else
            e->afficher(painter, xOrigine + (i * wElement) , yOrigine, wElement, hElement);
        i++;

    }


    for (int i = 0; i < rames.size(); i++) {
        Rame * r = rames.at(i);
        if (r->sens == Rame::Aller)
            r->afficher(painter, xOrigine + wElement*r->getPosition(), yOrigine, wElement, hElement);
        else
            r->afficher(painter, xOrigine - wElement + (wElement *r->getPosition()) + wElement, yOrigine - hElement, wElement, hElement);

    }

}


void Ligne::ajouterRame(Rame *rame)
{
    this->rames.push_back(rame);
}

QList<Rame *> * Ligne::getRames()
{
    return &this->rames;
}

Rame * Ligne::getRameAt(int i)
{
    return this->rames.at(i);
}

int Ligne::getLongueur()
{
    return this->longueur;
}
int Ligne::getNbRames()
{
    return this->rames.size();
}

void Ligne::updateListPSsuivant()
{
    qDebug() << "updateListPS $$$$$";
    bool last = true;
    PointSynchronisation * suivant;
    for (int i = this->aller.size() - 1; i >= 0; i--) {
        Element * e = this->aller.at(i);
        if (e->getClasse() == "Feu" || e->getClasse() == "Station") {
            PointSynchronisation * ps = dynamic_cast<PointSynchronisation *>(e);
            if (last) {
                ps->setSuivant(NULL);
                last = false;
                qDebug() << ps->getClasse() << " " << ps->getNum() << "\tsuivant : NULL" ;
            } else {
                ps->setSuivant(suivant);
            }
            suivant = ps;
        }
    }
    last = true;
    for (int i = 0; i < this->retour.size(); i++) {
        Element * e = this->retour.at(i);
        if (e->getClasse() == "Feu" || e->getClasse() == "Station") {
            PointSynchronisation * ps = dynamic_cast<PointSynchronisation *>(e);
            if (last) {
                ps->setSuivant(NULL);
                last = false;
                qDebug() << ps->getClasse() << " " << ps->getNum() << "\tsuivant : NULL" ;
            } else {
                ps->setSuivant(suivant);
                //qDebug()<< ps->getClasse() << " "<< ps->getNum() << "\tsuivant :"<< suivant->getClasse()<<" "<<suivant->getNum() ;
            }
            suivant = ps;
        }
    }
    qDebug() << "FIN updateListPS $$$$$";
}

void Ligne::updateListPSprecedent()
{
    bool last = true;
    PointSynchronisation * precedent;
    for (int i = 0; i < this->longueur; i++) {
        Element * e = this->aller.at(i);
        if (e->getClasse() == "Feu" || e->getClasse() == "Station") {
            PointSynchronisation * ps = dynamic_cast<PointSynchronisation *>(e);
            if (last) {
                ps->setPrecedent(NULL);
                last = false;
            } else {
                ps->setPrecedent(precedent);
            }
            precedent = ps;
        }
    }
    last = true;
    for (int i = this->retour.size() - 1; i >= 0; i--) {
        Element * e = this->retour.at(i);
        if (e->getClasse() == "Feu" || e->getClasse() == "Station") {
            PointSynchronisation * ps = dynamic_cast<PointSynchronisation *>(e);
            if (last) {
                ps->setPrecedent(NULL);
                last = false;
            } else {
                ps->setPrecedent(precedent);
                //qDebug()<< ps->getClasse() << " "<< ps->getNum() << "\tsuivant :"<< suivant->getClasse()<<" "<<suivant->getNum() ;
            }
            precedent = ps;
        }
    }
}

QList<Element *> * Ligne::getListeElement()
{
    return &this->listeElement;
}


QList <Station *> * Ligne::getStations()
{
    return &this->listeStation;
}

void Ligne::ajouterObstacle()
{
    int position = rand() % this->longueur;
    Obstacle * o = new Obstacle(&this->aller, position);
    //while()
    this->aller[position] = o;


}
