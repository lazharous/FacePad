#ifndef _QT4GUI_H_
#define _QT4GUI_H_

#include <QMainWindow>
#include "ui_qt4gui.h"
#include "game.h"


/**
* Classe che gestisce la finestra in Qt4, eredita anche la classe CGame in modo da
* poter creare la finestra e pilotare il gioco controllando questa classe soltanto.
* Implementa la classe QMainWindow dato che e' una finestra in Qt4 e ne eredita' le
* specifiche
*/
class qt4gui :
        public QMainWindow,
        public CGame
{
    Q_OBJECT

public:
    /// Costruttore della classe, si occupa di settare per default il parent a 0
    /// \param parent Mantiene l'ID della finestra creata
    qt4gui(QWidget *parent = 0);
    ~qt4gui();

public slots:
    /// Questo metodo puo' essere utilizzato dentro il QtCreator ma senza
    /// codice, il progetto qt non include le classi utilizzate nel progetto finale.
    /// Inizializza il gioco e lo manda il loop.
    void play();

protected:
    /// Usata internamente per stabilire se sono avvenuti dei cambiamenti
    void changeEvent(QEvent *e);

private:
    ui_qt4gui *ui; ///< Questo e' il puntatore alla classe, ed e' dove risiede la grafica della finestra
};

#endif // _QT4GUI_H_
