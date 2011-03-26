#ifndef PORTE_H
#define PORTE_H
#include "rame.h"

#include "gestionsignal.h"
class Porte: public GestionSignal
{
    bool open;
    bool ouvertureDemandee;
    Rame * rame;
public:
    Porte();
    void run();
    Porte(Rame * r);
    void ouvrir();
    void fermer();
    bool isOpen();
    void demanderOuverture();
    virtual QString getClasse(){ return QString("Porte.");}

    void createSignal();
};

#endif // PORTE_H
