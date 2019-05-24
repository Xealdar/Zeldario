#include "coincounter.h"

#include "coincounter.h"
#include <QFont>
#include<QFontDatabase>

CoinCounter::CoinCounter(QGraphicsItem *parent): QGraphicsTextItem(parent){

    coinCount = 0;

    //Affiche le texte du nombre de pièce
    int id = QFontDatabase::addApplicationFont(":font/count.png");
    QFontDatabase::applicationFontFamilies(id);
    setPlainText(QString("") + QString::number(coinCount));
    setDefaultTextColor(Qt::black);
    setFont(QFont("CoinCount2",40));
}

void CoinCounter::increase(){
    coinCount++;
    setPlainText(QString("") + QString::number(coinCount));
}

int CoinCounter::getCount(){
    return coinCount;
}
