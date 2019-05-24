#include "welcome.h"
#include "mainwindow.h"


welcome::welcome() : QWidget()
{
    setFixedSize(600, 400);


    // Construction des boutons
    QPushButton *play_button = new QPushButton("Jouer !", this);
    QPushButton *quit_button = new QPushButton("Quitter", this);

    // Construction des labels
    QLabel *text = new QLabel(this);

    // Configuration des labels
    text->setText("Bienvenue dans notre 'Hand Control' MARIO !");
    text->move(80,10);
    text->setStyleSheet("QLabel { background-color : red; color : white ; font: 16pt;  }");


    // configuration des boutons
    play_button->setCursor(Qt::PointingHandCursor);
    play_button->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/logo.png"));
    play_button->setIconSize(QSize(100, 50));
    play_button->move(100, 300);

    quit_button->setCursor(Qt::PointingHandCursor);
    quit_button->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/quit.png"));
    quit_button->setIconSize(QSize(100, 50));
    quit_button->move(320, 300);


    qApp->setStyleSheet("QWidget {background-image: url(./mario.jpg) }");


    //Configuration des signals
    QObject::connect(quit_button, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(play_button, SIGNAL(clicked()), qApp, SLOT());
}


