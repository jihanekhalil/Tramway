#include "troncon.h"

Troncon::Troncon()
{
}
Troncon::Troncon(int pLongueur)
{
    this->longueur=pLongueur;
    for(int i= 0; i<pLongueur; i++){
        this->parcours.push_back(NULL);
    }
}

bool Troncon::estFini(int position){
    return position<this->longueur;

}

void Troncon::setEtat(int position, Rame* rame){
    this->parcours[position] = rame;
}

QList<Rame *> Troncon::getParcours(){
    return this->parcours;
}
