#ifndef PORTE_H
#define PORTE_H

class Porte
{
    bool open;
    bool ouvertureDemandee;
public:
    Porte();
    void ouvrir();
    void fermer();
    bool isOpen();
    void demanderOuverture();
};

#endif // PORTE_H
