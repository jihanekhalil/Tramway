#include "passager.h"

Passager::Passager()
{

}

Passager::Passager(Station * pstatitionDest)
{
    this->stationDest = pstatitionDest;
}

Station * Passager::getStationDest(){
    return this->stationDest;
}

