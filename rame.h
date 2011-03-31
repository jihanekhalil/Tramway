#ifndef RAME_H
#define RAME_H
#include <QObject>
class Ligne;
class Porte;
class Passager;
#include "ligne.h"
#include "gestionsignal.h"
#include <QPainter>
#include "porte.h"
#include "pointsynchronisation.h"

class Rame: public GestionSignal
{    

public:
    /*
     * Type des Sens de la rame sur la ligne
     */
    enum Sens {
        Aller,
        Retour
    };

    Rame();
    ~Rame();
    Rame(Ligne * ligne);
    void run();

    /*
     * Affichage
     */
    void afficher(QPainter * painter, int x, int y, int, int);

    /*
     * Avance la rame d'une case. Gestion de l'arrivee a un feu ou station...
     */
    void avancer();

    /*
     * retourne la position de la rame sur la ligne
     */
    int getPosition();

    /*
     * Modifie la position de la rame sur la ligne (pour les test uniquement)
     */
    void setPosition(int);

    /*
     * Variable de classe comptant le nombre de rames creees
     */
    static int nbRame;

    /*
     * Retourne l'identifiant de la rame
     */
    int getNumRame();

    /*
     * Sens de la rame sur la ligne
     */
    Sens sens;

    int getNbPassager();

    void monte(QList <Passager *> plistepassager);

    QList <Passager *> descend(Station * pstation);

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

    QList <Passager *> listePassager;
};

#endif // RAME_H
