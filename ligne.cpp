#include "ligne.h"

Ligne::Ligne()
{
}

void Ligne::ajouterTroncon(Troncon * t){
    this->ligne.push_back(*t);
}

void Ligne::afficher(QPainter * painter){

    foreach(Troncon t,ligne){
        t.afficher(painter, 20,20);
    }
    cout <<endl;
}
