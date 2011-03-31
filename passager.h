#ifndef PASSAGER_H
#define PASSAGER_H

#include "personne.h"

class Station;

class Passager : public Personne
{
public:
    Passager();
    Passager(Station * pstatitionDest);
    Station * getStationDest();

private:
    Station * stationDest;
};

#endif // PASSAGER_H
