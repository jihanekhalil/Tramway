#include "porte.h"

Porte::Porte()
{
    this->open=false;
    this->ouvertureDemandee=false;
}
bool Porte::isOpen(){
    return this->open;
}

void Porte::fermer(){
    this->open=false;
    this->ouvertureDemandee = false;
}

// ouvre la porte si l'ouverture a été demandée
void Porte::ouvrir(){
    if(this->ouvertureDemandee){
        this->open=true;
    }
}

// demande l'ouverture de la porte
void Porte::demanderOuverture(){
    if(!this->ouvertureDemandee && !this->open){
        this->ouvertureDemandee=true;
    }
}
