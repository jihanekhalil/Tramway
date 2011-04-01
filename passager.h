/*
 *   Copyright 2011 by Jihane Khalil <khaliljihane@gmail.com>
 *   Copyright 2011 by Paul Labonne <paul.labonne@gmail.com>
 *   Copyright 2011 by Manuel Campomanes <campomanes.manuel@gmail.com>
 *   Copyright 2011 by Marc-Antoine Beauvais <marcantoine.beauvais@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef PASSAGER_H
#define PASSAGER_H

class Station;

class Passager
{
public:

    /**
     * @brief Constructeur d'un passager.
     */
    Passager();

    /**
     * @brief Constructeur d'un passager.
     * @param Une station
     */
    Passager(Station *);

    /**
     * @brief Destructeur d'un passager.
     */
    ~Passager();

    /**
     * @brief Recuperer la station de destination.
     * @return La station de destination du passager
     */
    Station * getStationDest();

private:

    /*
     * Station de destination du passager
     */
    Station * stationDest;
};

#endif // PASSAGER_H
