#include "signals.h"

Signals::Signals(GestionSignal * e, TypeSignal t)
{
    this->sigEmetteur = e;
    this->sigType = t;
}

void Signals::setEmetteur(GestionSignal * e)
{
    this->sigEmetteur = e;
}

Signals::TypeSignal Signals::type()
{
    return this->sigType;
}

GestionSignal * Signals::emetteur()
{
    return this->sigEmetteur;
}

Signals::~Signals()
{}

