#include "troncon.h"

using namespace std;
Troncon::Troncon()
{
}
Troncon::Troncon(int pLongueur)
{
    this->longueur=pLongueur;
    for(int i= 0; i<pLongueur; i++){
        this->parcours.push_back(NULL);
    }
    this->p1= new Station;
    this->p2= new Feux;
    this->p2->passerVert();
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
