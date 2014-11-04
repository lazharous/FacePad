#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <iostream>
#include "SDL.h"

/// Indica la larghezza della finestra da creare
#define WIDTH 640
/// Indica l'altezza della finestra da creare
#define HEIGHT 480
/// Indica la profondita' di colore
#define DEPTH 16

using namespace std;

/**
* Classe che gestisce ogni aspetto della grafica e degli eventi ad essa allegati
*/
class CGraphics
{
  public:
    /// Inizializza le SDL e prepara tutto per poter lavorare
    /// comodamente con la grafica
    /// \param name Indica il nome della finestra generata
    /// \param width Indica la larghezza della finestra
    /// \param height Indica l'altezza della finestra
    /// \param depth Indica la profondita' di colore usata
    void Init(const char *name, short width, short height, short depth);

    /// Esegue il polling per controllare se ci sono eventuali richieste in attesa da processare
    void pollEvents(void);

    /// Setta un colore come colore alpha, ovvero non viene disegnato a schermo
    /// \param img L'immagine su cui applicare l'alpha
    /// \param r Valore del colore rosso, da 0 a 255
    /// \param g Valore del colore verde, da 0 a 255
    /// \param b Valore del colore blu, da 0 a 255
    void setAlpha(SDL_Surface *img, int r, int g, int b);

    /// Carica un immagine in memoria
    /// \param filename Nome del file da caricare
    /// \return La struttura con l'immagine caricata, pronta per essere usata
    SDL_Surface *loadImage(char *filename);

    /// Disegna l'immagine nel buffer
    /// \param image L'immagine da disegnare nel buffer
    /// \param x La posizione della X dove disegnare l'immagine
    /// \param y La posizione della Y dove disegnare l'immagine
    void blitImage(SDL_Surface *image, int x, int y);

    /// Aggiorna la schermata e la disegna a video
    void updateScreen(void);

  private:
    SDL_Surface *screen; ///< Struttura che contiene l'handle per il disegno a video
};

#endif //_GRAPHICS_H_
