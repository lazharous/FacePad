/**
 * @file main.cpp
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

#include <QtGui/QApplication>
#include "qt4gui.h"

/**
 * Funzione principale, si occupa di inizializzare la classe
 * CGame allocandola in memoria, poi non fa altro che entrare
 * in un loop infinito in cui la classe CGame fa tutte le operazioni
 * principali del gioco.
*/
int main(int argc, char* argv[])
{
    // Creiamo una finestra in Qt4
    QApplication application(argc, argv);
    qt4gui *win = new qt4gui();

    // La mostra a video
    win->show();
    application.exec();

    return 0;
}

