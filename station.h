/*
 *   Copyright 2011 by Jihane Khalil <khaliljihane@gmail.com>
 *   Copyright 2011 by Paul Labonne <paul.labonne@gmail.com>
 *   Copyright 2011 by Manuel Campomanes <campomanes.manuel@gmail.com>
 *   Copyright 2011 by Marc-Antoine Beauvais <marcantoine.beauvais@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef STATION_H
#define STATION_H

#include "pointsynchronisation.h"
#include <iostream>
#include <QPainter>
#include <QString>
#include "params.h"
#include "passager.h"

class Station : public PointSynchronisation
{
public:
    /*
     * Type de la station
     */
    enum Type {
        Terminus,
        Intermediaire
    };

public:
    /**
     * @brief constructeur de Station.
     */
    Station();

    /**
     * @brief constructeur de Station.
     * @param nom de la ligne
     * @param type de station
     * @param une ligne
     */
    Station(QString nomLigne, Station::Type, Ligne *);

    /**
     * @brief Affichage graphique d'une station.
     * @param
     */
    void afficher(QPainter * painter, int x, int y, int, int, bool);

    /**
     * @brief Retourne le nom de la classe Station.
     * @return le nom de la classe
     */
    virtual QString getClasse() {
        return QString("Station");
    }

    /**
     * @brief Comportement d'une station.
     */
    void run();

    /**
     * @brief Retourne le nom de la station.
     * @return le nom de la station
     */
    QString getNom();

    /**
     * @brief Retourne ligne de la station.
     * @return la ligne de la station
     */
    Ligne * getLigne();

    /**
     * Gestion des signaux recus:
     * Signals::Demande
     * Signals::EstPasse : indique que la rame est partie, remet le feu a rouge.
     */
    void createSignal();

    /**
     * @brief Verifie le type de station.
     * @return station terminus = 1 sinon 0
     */
    bool estTerminus();

    /**
     * @brief Ajoute des passager en attente a la station.
     */
    void setPassagers();

public:
    /*
     * Variable de classe comptant le nombre de stations crees
     */
    static int nombreStations;

private:
    /*
     * Type de la station
     */
    Type typeStation;

    /*
     * Liste de passager
     */
    QList <Passager *> listePassager;

    /*
     * La ligne de la station
     */
    Ligne * maligne;

    /*
     * Le nom de la station
     */
    QString nom;
};


#endif // STATION_H
