#ifndef _GAME_H_
#define _GAME_H_

#include "faceTrack.h"
#include "graphics.h"
#include "asteroid.h"

/// Indica la velocita' con cui si sposta la nostra navicella
#define _PG_VEL 15

/// Indica che la navicella sta ferma
#define _POS_STEADY 0
/// Indica che si muove a destra
#define _POS_RIGHT 1
/// Indica che si muove a sinistra
#define _POS_LEFT 2

/// Numero massimo di asteroidi che possono essere creati contemporaneamente
#define MAX_ASTEROIDS 5

/**
* Classe principale, eredita sia CGraphics che CFaceTrack e incapsula CAsteroid,
* viene utilizzata per coordinare il tutto e realizzare un piccolo gioco basato sul
* riconoscimento del movimento del volto
*/
class CGame :
     public CGraphics,
     public CFaceTrack
{
  public:
    /// Costruttore della classe
    CGame();
    /// Distruttore della classe, dealloca gli asteroidi
    ~CGame();

    /// Inizializza il gioco
    void initGame();

    /// Genera degl asteroidi casualmente nel gioco
    void randomAsteroids(void);

    /// Gestisce il movimento del personaggio
    /// \param pg Indica la struttura che contiene la navicella
    /// \param moving Indica in che verso sta andando
    void moveCharacter(SDL_Surface *pg, short moving);

    /// Gestisce le collisioni asteroidi/giocatore e nel caso
    /// si occupa di resettare il "livello"
    void checkCollisions(void);

    /// Aggiorna la posizione in base al movimento del volto
    /// \param now Indica la posizione attuale del volto
    /// \param base Indica la posizione usata come riferimento per la rilevazione
    /// del movimento
    /// \return In che verso si sta muovendo
    short getPosition(Position now, Position base);

    /// Loop principale del gioco dove avviene la maggior parte dei
    /// controlli e delle operazioni
    void gameLoop(void);

  private:
    int collided;
    CAsteroid *a;
    SDL_Surface *pg, *bkg, *asteroid;
    int pg_x, pg_y;
};

#endif //_GAME_H_
