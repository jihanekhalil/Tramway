#ifndef PORTE_H
#define PORTE_H
#include "rame.h"

#include "gestionsignal.h"
class Porte: public GestionSignal
{

    /*
     * Etat de la porte: ouvert (true) ou fermee (false)
     */
    bool open;


    /*
     * Est ce que l'ouverture de la porte a ete demandee par un usager (true) ou non (false)
     */
    bool ouvertureDemandee;


    /*
     * Rame de la porte
     */
    Rame * rame;
public:
    Porte();
    void run();
    Porte(Rame * r);

    /*
     * Ouverture la porte si l'ouverture a été demandée
     */
    void ouvrir();

    /*
     * Fermeture de la porte
     */
    void fermer();


    /*
     * Retourne l'etat de la porte
     */
    bool isOpen();


    /*
     * Demande l'ouverture de la porte avant ou à l'arrivée a une station
     */
    void demanderOuverture();

    /*
     * Retourne le nom de la classe
     */
    virtual QString getClasse(){ return QString("Porte");}


    /*
     * Gestion des signaux:
     * Signals::OuvrirPorte : signal de la rame pour autoriser l'ouverture de la porte
     * Signals::FermerPorte : signal de la rame pour demander la fermeture de la porte.
     *    Renvoie un signal Signals::PorteFermee a la rame lorsque la porte est fermee.
     */
    void createSignal();
};

#endif // PORTE_H
