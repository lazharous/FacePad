/**
 * @file faceTrack.cpp
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

#include "faceTrack.h"

const char *wndName = "FacePad - Mainieri Paolo"; ///< Nome della finestra
String faceCascadeName = "data/haarcascade_frontalface_alt.xml"; ///< File di definizione per il riconoscimento dei volti

CFaceTrack::CFaceTrack()
{
    this->scale = 1.5f;
    this->capture = 0;
}

int CFaceTrack::Init()
{
    // Carica il file con le definizioni per il riconoscimento dei volti
    faceCascade.load( faceCascadeName );

    // Cattura il flusso video dalla webcam principale; 0!
    capture = cvCaptureFromCAM( 0 );

    cvNamedWindow( wndName, 1 );

    // Conferma l'avvenuta inizializzazione
    return (int)capture;
}

void CFaceTrack::Destroy(void)
{
    cvDestroyWindow(wndName);
}

void CFaceTrack::Release(void)
{
    cvReleaseCapture( &this->capture );
}

void CFaceTrack::Capture(void)
{
    img = cvQueryFrame( this->capture );
}

Position CFaceTrack::doTracking(Position &start)
{
    Mat smallImgSection, gray;
    Position ret;

    if (!(int)this->capture)
    {
        cout << "Errore: Libreria CFaceTrack non inizializzata." << endl;
        exit(1);
    }

    // inizializza la struttura di ritorno
    ret.set = 0;

    Scalar color = colors[0];

    start.radius = cvRound((img.rows + img.cols)*0.15);

    // Ottiene il centro dello schermo
    start.center.x = cvRound((img.rows*0.5 + start.radius*0.5));
    start.center.y = cvRound((img.cols*0.5 - start.radius*0.5));

    circle( img, start.center, start.radius, color, 3, 8, 0 );

    // Crea un immagine piu' piccola per velocizzare il rilevamento
    // P.S.: ridimensiona l'immagine sorgente, precisamente
    Mat smallImg( cvRound(img.rows/scale), cvRound(img.cols/scale), CV_8UC1 );

    // Crea un immagine in scala di grigi e la ridimensiona
    cvtColor( img, gray, CV_BGR2GRAY );
    resize( gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR );
    equalizeHist( smallImg, smallImg );

    // Identifica i volti presenti nell'immagine
    faceCascade.detectMultiScale( smallImg, face, 1.1, 2, CV_HAAR_SCALE_IMAGE, Size(30, 30) );

    if (!face.empty())
    {
        color = colors[6];

        ret.center.x = cvRound((face[0].x + face[0].width*0.5)*scale);
        ret.center.y = cvRound((face[0].y + face[0].height*0.5)*scale);

        ret.radius = cvRound((face[0].width + face[0].height)*0.25*scale);

        circle( img, ret.center, ret.radius, color, 3, 8, 0 );

        ret.set = 1;
    }

    return ret;
}

void CFaceTrack::showImage(void)
{
    imshow( wndName, img );
    waitKey(10);
}
