#include "welcome.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;

    //w.show();

    welcome fenetre;
    fenetre.show();

    return a.exec();



}
