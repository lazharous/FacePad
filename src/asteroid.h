#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include "graphics.h"

/**
* Classe utilizzata per il movimento e la creazione
* degli asteroidi e la loro stampa a video
*/
class CAsteroid
{
    public:
        CAsteroid(){}
        /// costruttore della classe
        CAsteroid(int v, int x, int y);

        /** Crea un nuovo asteroide
         * \param v Indica la velocita' dell'asteroide
         * \param x Indica la posizione della X al momento t0
         * \param y Indica la posizione della Y al momento t0
        */
        void Create(int v, int x, int y);

        /// Imposta la visibilita' dell'asteroide
        void setActive(int act);

        /// \return 1 se l'asteroide e' attivo, 0 altrimenti
        int getActive(void);

        /// \return La posizione della X
        int getX(void){ return x; }

        /// \return La posizione della Y
        int getY(void){ return y; }

        /// \return La velocita' dell'asteroide
        int getVel(void){ return vel; }

        /// Aggiorna la posizione dell'asteroide
        /// \param img Usato per disegnare a video l'asteroide
        void Update(SDL_Surface *img);

    private:
        int active; ///< Indica se l'asteroide e' attivo o meno
        int x,y; ///< Indica la posizione attuale dell'asteroide
        int vel; ///< Indica la velocita' dell'asteroide
};

#endif //_ASTEROID_H_

