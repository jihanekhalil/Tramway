#ifndef LIGNE_H
#define LIGNE_H
class Rame;
class Station;
#include <QList>
#include <iostream>
#include "element.h"
#include "rame.h"
#include <QPainter>
using namespace std;
class Ligne
{
public:
    Ligne();
    ~Ligne();
    Ligne(int longueur);

    /*
     * Affichage
     */
    void afficher(QPainter * painter, int, int);

    /*
     * Ajoute une rame a la ligne
     */
    void ajouterRame(Rame * rame);

    /*
     * Ajoute une rame a la ligne
     */
    void updateListPS();

    /*
     * Retourne la liste des rames
     */
    QList<Rame *> * getRames();

    /*
     * Retourne la rame num i de la liste des rames
     */
    Rame * getRameAt(int);

    /*
     * Retourne la longueur de la ligne
     */
    int getLongueur();

    /*
     * Retourne le nombre de rames (taille de la liste)
     */
    int getNbRames();

    /*
     * Retourne le pointeur d'element a la position donnee
     */
    Element * getElementAt(int i, bool);

    /*
     * Retourne le pointeur d'element a la position donnee
     */
    Element * ElementExists(int i);

    QList<Element *> * getListeElement();

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

    QList<Element *> listeElement;

    QList<Station *> listeStation;
};

#endif // LIGNE_H
