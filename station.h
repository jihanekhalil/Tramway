#ifndef STATION_H
#define STATION_H
#include "pointsynchronisation.h"
#include <iostream>
#include <QPainter>
#include <QString>
#include "params.h"
#include "passager.h"

using namespace std;

class Station : public PointSynchronisation{
public:
    /*
     * Type de la station
     */
    enum Type
    {
        Terminus,
        Intermediaire
    };
    /*
     * Variable de classe comptant le nombre de stations crees
     */
    static int nombreStations;
    Station();
    Station(QString,Station::Type, Ligne * pligne);

    void afficher(QPainter * painter, int x, int y, int, int, bool);
    virtual QString getClasse(){ return QString("Station");}
    void run();
    QString getNom();
    Ligne * getLigne();

    /*
     * Gestion des signaux recus:
     * Signals::Demande
     * Signals::EstPasse : indique que la rame est partie, remet le feu a rouge.
     */
    void createSignal();

    void setPassagers();

private:
    Type typeStation;
    QList <Passager *> listePassager;
    Ligne * maligne;
    QString nom;
};


#endif // STATION_H
