#include "mainwindow.h"

#include <QDebug>

#include <QLabel>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    MainWindow::createScene();

}

MainWindow::~MainWindow()
{

}

void MainWindow::createScene()
{


    scene = new Scene();
    view = new View(scene);



}

void MainWindow::repaint()
{

}
