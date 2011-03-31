#ifndef SIGNALS_H
#define SIGNALS_H

class Signals;

#include "gestionsignal.h"


class Signals
{
public:
    enum TypeSignal {
        Demande,
        EstPasse,
        Arret,
        Passe,
        OuvrirPorte,
        FermerPorte,
        PorteFermee
    };

    Signals(GestionSignal*, TypeSignal);
    ~Signals();
    GestionSignal * emetteur();
    void setEmetteur(GestionSignal *);
    TypeSignal type();

private:
    TypeSignal sigType;
    GestionSignal * sigEmetteur;

};

#endif // SIGNALS_H
