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

#ifndef PORTE_H
#define PORTE_H

#include "rame.h"
#include "gestionsignal.h"

class Porte: public GestionSignal
{
public:
    /**
     * @brief Constructeur d'une porte.
     */
    Porte();

    /**
     * @brief Constructeur d'une porte.
     */
    Porte(Rame * r);

    /**
     * @brief Destructeur d'une porte.
     */
    ~Porte();

    /**
     * @brief Comportement d'une porte.
     */
    void run();    

    /**
     * @brief Ouverture de la porte.
     */
    void ouvrir();

    /**
     * @brief Fermeture de la porte.
     */
    void fermer();


    /**
     * @brief Retourne l'etat de la porte.
     */
    bool isOpen();

    /**
     * @brief Affichage graphique d'une porte.
     * @param
     */
    void afficher(QPainter * painter, int x, int y, int wPorte, int hElement);

    /**
     * @brief Demande l'ouverture de la porte avant ou à l'arrivée a une station.
     */
    void demanderOuverture();

    /**
     * @brief Retourne le nom de la classe Porte.
     * @return le nom de la classe
     */
    virtual QString getClasse() {
        return QString("Porte");
    }

    /**
     * @brief Retourne l'identificateur de porte.
     * @return l'id de la porte
     */
    int getNumPorte() {
        return numPorte;
    }

    /**
     * @brief Gestion des signaux:
     * Signals::OuvrirPorte : signal de la rame pour autoriser l'ouverture de la porte
     * Signals::FermerPorte : signal de la rame pour demander la fermeture de la porte.
     *    Renvoie un signal Signals::PorteFermee a la rame lorsque la porte est fermee.
     */
    void createSignal();

public:
    /*
     * Variable de classe numéro de porte
     */
    static int nombrePortes;

private:
    /*
     * Etat de la porte: ouvert (true) ou fermee (false)
     */
    bool open;

    /*
     * Identificateur de porte
     */
    int numPorte;

    /*
     * Est ce que l'ouverture de la porte a ete demandee par un usager (true) ou non (false)
     */
    bool ouvertureDemandee;

    /*
     * Rame de la porte
     */
    Rame * rame;
};

#endif // PORTE_H
