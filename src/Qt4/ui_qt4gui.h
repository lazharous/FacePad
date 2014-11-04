#ifndef _UI_QT4GUI_H_
#define _UI_QT4GUI_H_

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

/**
* Classe utilizzata per inizializzare gli oggetti presenti all'interno della finestra Qt.
*/
class ui_qt4gui
{
public:
    /// Contiene l'indice della finestra
    QWidget *centralWidget;
    /// Contiene una label
    QLabel *lbl1;
    /// Bottone usato per far partire il "gioco" (you lost the game) :]
    QPushButton *pshPlay;
    /// Bottone usato per chiudere la finestra Qt
    QPushButton *pshClose;

    /// Si occupa di inizializzare la grafica
    void setupUi(QMainWindow *qt4gui)
    {
        if (qt4gui->objectName().isEmpty())
            qt4gui->setObjectName(QString::fromUtf8("qt4gui"));

        qt4gui->resize(388, 101);

        // Inizializza la finestra
        centralWidget = new QWidget(qt4gui);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        
        // Crea la label, le da il nome e la posiziona
        lbl1 = new QLabel(centralWidget);
        lbl1->setObjectName(QString::fromUtf8("lbl1"));
        lbl1->setGeometry(QRect(10, 10, 371, 17));

        // Crea il bottone di avvio gioco, gli da il nome e lo posiziona
        pshPlay = new QPushButton(centralWidget);
        pshPlay->setObjectName(QString::fromUtf8("pshPlay"));
        pshPlay->setGeometry(QRect(280, 60, 93, 27));

        // Crea il bottone di uscita, gli da il nome e lo posiziona
        pshClose = new QPushButton(centralWidget);
        pshClose->setObjectName(QString::fromUtf8("pshClose"));
        pshClose->setGeometry(QRect(180, 60, 93, 27));

        qt4gui->setCentralWidget(centralWidget);

        retranslateUi(qt4gui);

        QMetaObject::connectSlotsByName(qt4gui);
    }

    /// Aggiunge alcune proprieta' alla GUI.
    void retranslateUi(QMainWindow *qt4gui)
    {
        qt4gui->setWindowTitle(QApplication::translate("qt4gui", "qtFacePad - [Mainieri Paolo]", 0, QApplication::UnicodeUTF8));
        lbl1->setText(QApplication::translate("qt4gui", "FacePad, il controller basato sul movimento del volto.", 0, QApplication::UnicodeUTF8));
        pshPlay->setText(QApplication::translate("qt4gui", "Gioca", 0, QApplication::UnicodeUTF8));
        pshClose->setText(QApplication::translate("qt4gui", "Esci", 0, QApplication::UnicodeUTF8));
    }

};

QT_END_NAMESPACE

#endif // _UI_QT4GUI_H_
