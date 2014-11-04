#include "qt4gui.h"

qt4gui::qt4gui(QWidget *parent) :
    QMainWindow(parent),
    ui(new ui_qt4gui)
{
    ui->setupUi(this);

    /// Crea una connessione tra evento in Qt e funzione/metodo in C++
    connect(ui->pshClose, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->pshPlay, SIGNAL(clicked()), this, SLOT(play()));
}

qt4gui::~qt4gui()
{
    delete ui;
}

void qt4gui::play()
{
    this->initGame();

    ui->pshPlay->setEnabled(false);

    for (;;)
        this->gameLoop();
}

void qt4gui::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
