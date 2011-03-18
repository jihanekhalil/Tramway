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

void Troncon::afficher(QPainter* painter, int x, int y){

    painter->drawRect(20,30,10*this->longueur, 5);
    this->p2->afficher(painter,15+(this->longueur*10),22);
    this->p1->afficher(painter,20,25);

    /*for(int i = 0; i < this->longueur; i++){
        if(i==0) this->p1->afficher(painter);
        else if(i== this->longueur-1) p2->afficher(painter);
        else cout << " ";
    }
    cout << endl;
    for(int i = 0; i < this->longueur; i++){
        if(this->parcours[i]!=NULL)
            this->parcours[i]->afficher(painter);
        else
            cout << "-";
    }
    cout << endl;
*/
}
