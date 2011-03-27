#ifndef POINTSYNCHRONISATION_H
#define POINTSYNCHRONISATION_H

#include <iostream>
#include <QPainter>

#include "element.h"
#include "rame.h"

using namespace std;

class PointSynchronisation: public Element
{
protected:
        /*
         * Couleur du feur : Vert (true) ou Rouge (false)
         */
        bool vert;


        /*
         * Identificateur du point de synchro
         */
        int numPS;

        /*
         * Derniere rame passee
         */
        GestionSignal * derniereRame;
public:

        PointSynchronisation();
        /*
         * Affichage
         */
        virtual void afficher(QPainter * painter, int x, int y, int , int);

        /*
         * Retourne la couleur du feu
         */
        bool estVert();

        /*
         * Retourne le pointeur du thread de la derniere rame
         */
        GestionSignal * getDerniereRame();

        /*
         * Passage au rouge du feu
         */
        void passerRouge();

        /*
         * Passage au vert du feu
         */
        void passerVert();


        /*
         * Retourne l'identifiant du PS
         */
        int getNum();

};

#endif // POINTSYNCHRONISATION_H
