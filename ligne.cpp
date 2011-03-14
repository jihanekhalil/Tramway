#include "ligne.h"

Ligne::Ligne()
{
}

void Ligne::ajouterTroncon(Troncon * t){
    this->ligne.push_back(*t);
}

void Ligne::afficher(){

    foreach(Troncon t,ligne){
        t.afficher();
    }
    cout <<endl;
}
