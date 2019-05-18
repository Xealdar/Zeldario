#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <view.h>
#include <scene.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void setSize();
    ~MainWindow();

private:
    void createScene();
    View *view;
    Scene *scene;
    void repaint();




};

#endif // MAINWINDOW_H
