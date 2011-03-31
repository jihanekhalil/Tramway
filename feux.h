#ifndef FEUX_H
#define FEUX_H
#include "pointsynchronisation.h"
#include <iostream>
#include "thread.h"
#include "ligne.h"
using namespace std;
class Feux : public PointSynchronisation
{

public:
    Feux();
    ~Feux();
    Feux(Ligne * ligne);
    void run();

    /*
     * Indique si une rame est présente ou non entre lui et le feux suivant.
     */
    bool voieLibre();

    /*
     * Affichage
     */
    virtual void afficher(QPainter * painter, int x, int y, int, int);

    /*
     * Retourne la position du feu sur la ligne
     */
    int getPosition();

    /*
     * Retourne le nom de la classe
     */
    virtual QString getClasse() {
        return QString("Feu");
    }

    /*
     * Gestion des signaux.
     * Signal::Demande : renvoie un Signals::Arret si le feu est rouge ou une autorisation de passage Signals::Passage
     * Signal::Demande : la rame vient de franchir le feu => passage au rouge
     */
    void createSignal();

public:
    /*
     * Variable de classe comptant le nombre de feux crees
     */
    static int nombreFeux;

private:
    /*
     * Ligne du feu.
     */
    Ligne * ligne;

    /*
     * Position du feu sur la ligne.
     */
    int position;
};

#endif // FEUX_H
