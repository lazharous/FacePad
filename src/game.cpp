/**
 * @file game.cpp
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

#include "game.h"

CGame::CGame()
{
    collided=0;
    pg_x=250;
    pg_y=380;

    // alloca memoria per gli asteroidi
    a = new CAsteroid[MAX_ASTEROIDS];
}

CGame::~CGame()
{
    delete[] a;
}

void CGame::initGame()
{
    // Inizializza il controller
    CFaceTrack::Init();
    // Inizializza uno schermo a 800x600 con 16bit di profondita'
    CGraphics::Init("Asteroids & FacePad", WIDTH, HEIGHT, DEPTH);

    // Carica il PG
    pg = loadImage((char*)"data/alien.bmp");
    asteroid = loadImage((char*)"data/enemy.bmp");
    bkg = loadImage((char*)"data/earth.bmp");

    // Usa il canale alpha e evita di disegnare il ciano
    setAlpha(pg, 255,0,255);
    setAlpha(asteroid, 255,0,255);
}


void CGame::randomAsteroids(void)
{
    int v,x;
    srand( time(NULL) );

    // se e' colliso, ricomincia da 0
    if (collided)
        for(int i=0; i<MAX_ASTEROIDS; i++)
        {
            a[i].setActive(0);
            collided=0;
        }

    //
    for (int i=0; i<MAX_ASTEROIDS; i++)
    {
        if (!a[i].getActive())
        {
            v = (rand() % 13)+3;
            x = rand() % (WIDTH-30);
            a[i].Create(v,x,0);
            a[i].Update(asteroid);

            a[i].setActive(1);

            blitImage(asteroid, x,0);
        }
        else
        {
            a[i].Update(asteroid);
            blitImage(asteroid, a[i].getX(), a[i].getY());
        }
    }
}


void CGame::checkCollisions(void)
{
    for(int i=0; i<MAX_ASTEROIDS; i++)
    {
        int left = a[i].getX();
        int right = left + asteroid->w;
        int top = a[i].getY();
        int bottom = top + asteroid->h;

        // Collisioni
        if (right > pg_x && left < pg_x && bottom >= pg_y)
            collided=1;
        else if (left < pg_x+pg->w && right > pg_x+pg->w && bottom >= pg_y)
            collided=1;
    }
}


void CGame::moveCharacter(SDL_Surface *pg, short moving)
{
    if (moving == _POS_RIGHT && (pg_x + pg->w + _PG_VEL < WIDTH))     pg_x = pg_x+_PG_VEL;
    else if (moving == _POS_LEFT && (pg_x - _PG_VEL > 0)) pg_x = pg_x-_PG_VEL;

    blitImage(pg, pg_x, pg_y);
}


short CGame::getPosition(Position now, Position base)
{
    // Se la posizione e' oltre i bordi del cerchio iniziale
    // allora aggiorna la posizione altrimenti non fa nulla
    short moving = _POS_STEADY;

    // Se non ha riconosciuto il volto e' inutile computare, resta
    // fermo dove sei e basta!!
    if (!now.set)
        return moving;

    if ((now.center.x - now.radius) < (base.center.x - base.radius))
        moving = _POS_RIGHT;
    else if ((now.center.x + now.radius) > (base.center.x + base.radius))
        moving = _POS_LEFT;

    return moving;
}


void CGame::gameLoop(void)
{
    short moving = _POS_STEADY;
    static Position base;

    // Controlla se ci sono eventi da processare
    pollEvents();
    // Per prima cosa catturiamo il flusso video
    Capture();
    // Muove il personaggio in base alla posizione presa
    // dal tracciamento della posizione del volto
    moving = getPosition( doTracking( base ), base );

    // Ridisegna lo sfondo per prima cosa
    blitImage(bkg, 0, 0);

    // Muove il personaggio in base al movimento eseguito
    moveCharacter( pg, moving );

    checkCollisions();

    // Crea e muove gli asteroidi
    randomAsteroids();

    // Aggiorna lo schermo e disegna tutto
    updateScreen();

    showImage();
}
