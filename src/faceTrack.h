#ifndef _TRACK_FACE_
#define _TRACK_FACE_

#include "cv.h"
#include "highgui.h"
#include <iostream>
#include <cstdio>

#define _DEBUG_

using namespace std;
using namespace cv;

/// Struttura contenente i vari colori
/// utilizzati per disegnare i cerchi quando vengono
/// rilevati i volti
const static Scalar colors[] =
{
  CV_RGB(0,0,255),
  CV_RGB(0,128,255),
  CV_RGB(0,255,255),
  CV_RGB(0,255,0),
  CV_RGB(255,128,0),
  CV_RGB(255,255,0),
  CV_RGB(255,0,0),
  CV_RGB(255,0,255)
};

/// Struttura usata per il controllo
/// della posizione, utilizzata da doTracking()
typedef struct
{
  Point center; ///< Struttura che contiene i valori x,y
  int radius; ///< Contiene la grandezza del raggio del cerchio
  int set; ///< Indica se la rilevazione del volto e' avvenuta con 1 e 0 altrimenti
} Position;

/**
* Classe utilizzata per il rilevamento e il tracciamento dinamico di volti
* attraverso un flusso video proveniente da una webcam
*/
class CFaceTrack
{
  public:
    /// Imposta i valori di base per l'utilizzo corretto della classe
    CFaceTrack();

    /// Si occupa di inizializzare il flusso video della webcam e di caricare i modelli statistici
    /// dei volti, oltre a ritornare vero se inizializza tutto correttamente
    /// \return 1 se inizializzata correttamente, 0 altrimenti
    int Init();

    /// Si occupa di eliminare la finestra
    void Destroy();

    /// Esegue il rilevamento del volto, prima crea un cerchio di base
    /// come punto di partenza per la rilevazione successiva del movimento,
    /// poi ridimensiona l'immagine del flusso per velocizzarne la rilevazione,
    /// successivamente converte l'immagine in scala di grigi. A questo punto
    /// trova il volto, disegna un cerchio intorno ad esso e ne ritorna la posizione.
    /// \param start Contiene la posizione del cerchio usato come base.
    /// \return La posizione attuale del volto, se riconosciuto.
    Position doTracking(Position &start);

    /// Mostra una finestra con il risultato delle elaborazioni sul rilevamento dei volti
    void showImage();

    /// Rilascia le risorse occupate in memoria
    void Release();

    /// Prende il flusso video dalla webcam e salva
    /// ogni singolo frame per la sua successiva elaborazione
    /// nella variabile (matrice) img
    void Capture();

  private:
    /// Lavorando su un immagine piu' piccola ci permette di diminuire drasticamente
    /// il tempo di esecuzione di ogni singola iterazione, peccando in precisione
    double scale;
    /// vettore di Rect, che conterra' i volti rilevati
    vector<Rect> face;
    Mat img;
    CvCapture* capture;
    CascadeClassifier faceCascade;
};

#endif //_TRACK_FACE_
