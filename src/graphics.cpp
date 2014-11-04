/**
 * @file graphics.cpp
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

#include "graphics.h"

void CGraphics::Init(const char *name, short width, short height, short depth)
{
    this->screen = SDL_SetVideoMode(width, height, depth, SDL_SWSURFACE);

    if ( screen == NULL )
    {
        cout << "Impossibile usare la risoluzione a " << width << "x" << height << ": " << SDL_GetError() << endl;
        exit(1);
    }
    
    SDL_WM_SetCaption( name, NULL );
}

SDL_Surface *CGraphics::loadImage(char *filename)
{
    SDL_Surface *image;

    // Carica l'immagine nella struttura
    image = SDL_LoadBMP(filename);
    if ( image == NULL )
    {
        cout << "Impossibile caricare l'immagine: " << SDL_GetError() << endl;
        exit(1);
    }

    return image;
}

void CGraphics::pollEvents(void)
{
    SDL_Event event;

    while( SDL_PollEvent( &event ) )
        if( event.type == SDL_QUIT )
            exit(0);
}

void CGraphics::setAlpha(SDL_Surface *img, int r, int g, int b)
{
    SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, r,g,b));
}

void CGraphics::blitImage(SDL_Surface *image, int x, int y)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    dest.w = image->w;
    dest.h = image->h;

    SDL_BlitSurface(image, NULL, screen, &dest);
}

void CGraphics::updateScreen(void)
{
    SDL_Flip(screen);
}
