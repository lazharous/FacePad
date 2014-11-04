/**
 * @file asteroid.cpp
 * @author Mainieri Paolo
 * @section Licensa
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section Descrizione
*/

#include "asteroid.h"

CAsteroid::CAsteroid(int v, int x, int y)
{
    Create(v,x,y);
}

void CAsteroid::Create(int v, int x, int y)
{
    active=0;
    this->vel = v;
    this->x = x;
    this->y = y;
}

void CAsteroid::setActive(int act)
{
    active = act;
}

int CAsteroid::getActive(void)
{
    return active;
}

void CAsteroid::Update(SDL_Surface *img)
{
    if (this->y + img->h > HEIGHT)
        active = 0;

    this->y += this->vel;
}
