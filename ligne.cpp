#include "ligne.h"

Ligne::Ligne()
{
}

void Ligne::ajouterTroncon(Troncon t){
    this->ligne.push_back(t);
}
