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

#ifndef LIGNE_H
#define LIGNE_H

class Rame;
class Station;

#include <QList>
#include <iostream>
#include "element.h"
#include "rame.h"
#include <QPainter>

class Ligne
{
public:
    
    /**
     * @brief Constructeur d'une ligne.
     */
    Ligne();
    
    /**
     * @brief Constructeur d'une ligne.
     * @param Longueur de la ligne
     */
    Ligne(int longueur);
    
    /**
     * @brief Destructeur d'une ligne.
     */
    ~Ligne();
    
    /**
     * @brief Affichage graphique d'une ligne.
     * @param
     */
    void afficher(QPainter * painter, int, int);

    /**
     * @brief Ajout d'une rame à la ligne.
     * @param
     */
    void ajouterRame(Rame * rame);

    /**
     * @brief Definir les objets suivants de chaque points.
     */
    void updateListPSsuivant();

    /**
     * @brief Definir les objets precedents de chaque points.
     */
    void updateListPSprecedent();

    /**
     * @brief Ajouter un obstacle sur la ligne.
     */
    void ajouterObstacle();

    /**
     * @brief Recuperer la liste de rames.
     * @return Une liste de rame
     */
    QList<Rame *> * getRames();

    /**
     * @brief Recuperer une rame à une position donnee.
     * @param Position sur la ligne
     */
    Rame * getRameAt(int);

    /**
     * @brief Recuperer la longueur de la ligne.
     * @return La longueur de la ligne
     */
    int getLongueur();

    /**
     * @brief Recuperer le nombre de rame de la ligne.
     * @return Le nombre de rame
     */
    int getNbRames();

    /**
     * @brief Recuperer l'element de la position donnee.
     * @return Un element
     * @param Une position
     * @param ligne allee=1 | retour=0
     */
    Element * getElementAt(int i, bool);    

    /**
     * @brief Recuperer la liste des elements de la ligne.
     * @return Une liste d'element
     */
    QList<Element *> * getListeElement();

    /**
     * @brief Recuperer la liste des stations de la ligne.
     * @return Une liste de station
     */
    QList <Station *> * getStations();

private:
    /*
     * Liste d'element constituants l'aller
     */
    QList<Element *> aller;

    /*
     * Liste d'element constituants le retour
     */
    QList<Element *> retour;

    /*
     * Liste des rames présentes sur la ligne
     */
    QList<Rame *> rames;

    /*
     * Longueur de la ligne
     */
    int longueur;

    /*
     * Liste d'element présent sur la ligne
     */
    QList<Element *> listeElement;

    /*
     * Liste de station présente sur la ligne
     */
    QList<Station *> listeStation;
};

#endif // LIGNE_H
