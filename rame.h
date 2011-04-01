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

#ifndef RAME_H
#define RAME_H

class Ligne;
class Porte;
class Passager;

#include <QObject>
#include "ligne.h"
#include "gestionsignal.h"
#include <QPainter>
#include "porte.h"
#include "pointsynchronisation.h"

class Rame: public GestionSignal
{

public:    

    /**
     * @brief Constructeur d'une rame.
     */
    Rame();

    /**
     * @brief Constructeur d'une rame.
     * @param une ligne
     */
    Rame(Ligne *);

    /**
     * @brief Destructeur d'une rame.
     */
    ~Rame();

    /**
     * @brief Comportement d'une rame.
     */
    void run();

    /**
     * @brief Affichage graphique d'une porte.
     * @param
     */
    void afficher(QPainter * painter, int x, int y, int, int);

    /**
     * @brief Avance la rame d'une case.
     */
    void avancer();

    /**
     * @brief Retourne la position de la rame sur la ligne.
     * @return la position de la rame
     */
    int getPosition();

    /**
     * @brief Modifie la position de la rame sur la ligne.
     * @param une position
     */
    void setPosition(int);

    /**
     * @brief Retourne l'id de la rame.
     * @return id d'une rame
     */
    int getNumRame();

    /**
     * @brief Retourne le nombre de passager.
     * @return nombre de passager
     */
    int getNbPassager();

    /**
     * @brief Faire monter un groupe de passager dans la rame.
     * @param Liste de passager
     */
    void monte(QList <Passager *> plistepassager);

    /**
     * @brief Faire descendre un groupe de passager de la rame.
     * @param Une station
     * @return Un groupe de passager
     */
    QList <Passager *> descend(Station * pstation);

    /**
     * @brief Vider la liste de passager.
     */
    void razListePassager();

public:    
    /*
     * Type des Sens de la rame sur la ligne
     */
    enum Sens {
        Aller,
        Retour
    };

    /*
     * Variable de classe comptant le nombre de rames creees
     */
    static int nbRame;        

    /*
     * Sens de la rame sur la ligne
     */
    Sens sens;   

private:
    /*
     * Nombre de portes ouvertes (utile en station)
     */
    int nbPortesOuvertes;

    /*
     * Mutex
     */
    pthread_mutex_t mutex;

    /*
     * Ligne de la rame
     */
    Ligne* ligne;

    /*
     * Position de la rame sur la ligne
     */
    int position;

    /*
     * Identificateur de la rame
     */
    int numRame;

    /*
     * Nombre de portes par coté de la rame (Nombre total de porte : nbPorte*2)
     */
    int nbPortes;

    /*
     * Liste des portes du cote droit de la rame
     */
    QList<Porte *> portesDroite;

    /*
     * Liste des portes du cote gauche de la rame
     */
    QList<Porte *> portesGauche;

    /*
     * Gestion des signaux:
     * Signals::Arret : Arret de la rame (feux rouge par exemple)
     * Signals::Passe : emetteur feu : passage puis renvoi de Signals::EstPasse au feu
     * Signals::Passe : emetteur Station : Envoi de Signals::FermerPorte a toutes les portes
     *                           (droite ou gauche selon le sens)
     * Signals::PorteFermee : Decremente le nbPortesOuvertes. Une fois à 0 la rame repart et envoie Signal::EstPasse
     */
    void createSignal();

    /*
     * Liste de passager
     */
    QList <Passager *> listePassager;
};

#endif // RAME_H
