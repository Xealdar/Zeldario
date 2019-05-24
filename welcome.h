#ifndef WELCOME_H
#define WELCOME_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>



class welcome : public QWidget // On hérite de QWidget (IMPORTANT)
{
public:
    welcome();

private:
    QPushButton *play_button;
    QPushButton *quit_button;
    QLabel *text;
    QLabel *image;
};

#endif // WELCOME_H




