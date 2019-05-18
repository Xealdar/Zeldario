#include "view.h"
#include "QDebug"
#include <scene.h>

View::View(QGraphicsScene *scene)
{


    View::setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    View::setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(scene);
    View::show();
}

void View::resizeEvent(QResizeEvent *event)
{
    if(scene() != NULL)
    {
        scene()->setSceneRect(0,0,this->size().width(),this->size().height());
        itemsList = scene()->items();

        //qDebug()<<"view : "<<this->size().width()<<this->size().height()<<" scene : "<<scene()->width()<<scene()->height();




        //dynamic_cast<Background*>(itemsList[0])->setPixmapSize(10,10);
        //dynamic_cast<Background*>(itemsList[1])->setPixmapSize(10,100);
        //dynamic_cast<Mario*>(itemsList[2])->setPixmapSize(this->size().width(),this->size().height());

        dynamic_cast<Background*>(itemsList[1])->setPixmapSize(this->size().width(),100);
        dynamic_cast<Background*>(itemsList[2])->setPixmapSize(this->size().width(),this->size().height());

    }

}




/*
 * S'il n'y a qu'une scène pour chaque vue, je peux mettre la
 * scène directement dans ma vue. Plutôt que faire un sceneset
 * je peux créer la scène directement dans le constructeur de la
 * view.
 * Ensuite on instancie la scène dans la mainwindow.
 * Si j'ai besoin de faire une minimap ou un truc comme ça
 * faut créer une autre vue avec une autre scène.
 *
 * Dans le modèle pour les différents persos, je peux
 * mettre les méthodes jump move etc. Ces méthodes sont
 * ensuite appeler par le contrôleur.
 * Le contrôleur (au moins le principal) sera un singleton qui
 * gère tout.
 *
 * Dans la vue on va faire les méthodes pour checker s'il y a des
 * keyPressed, et c'est le contrôleur qui va utiliser
 * ces méthodes pour checker si une key est pressed
 * et process en fonction. Après avoir process il dit
 * à la vue ce qu'elle doit afficher (on update la scène ou on
 * change de scène.)
 *
 * Le virtual sert à faire une méthode générique, qu'on
 * va personnaliser pour chaque classe. Très intéressant du coup
 * pour une classe monstre ou personnage.
 *
 * Pour les monstres identiques et coins identiques etc, le mieux
 * c'est de faire une classe mère pour laquelle on va charger un pixmap
 * plutôt que de charger plein de pixmap.
 *
 * Il vaut mieux créer le smallcharact en tant que méthode du
 * charact principal, sinon il va falloir en kill un chaque fois
 * pour instancier l'autre c'est bof
 * je peux faire un bool pour gérer sa puissance etc en fonction
 * de s'il est small ou pas
 *
 *
 * Ne pas faire hériter mario d'un QgraphicsView, par
 * contre donner à mario un marioWidget qui lui
 * hérite d'un QGraphicsView
 *
 * thread d'action
 * thread d'ia
 * thread de ?
*/
