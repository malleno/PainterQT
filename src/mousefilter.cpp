#include "mousefilter.h"
#include "QEvent"
#include "QDebug"
#include "QMouseEvent"

MouseFilter::MouseFilter(QObject *parent, GameScene* game_scene) :
    QObject(parent),
    material_painter_(new materialPainter(this, game_scene))
{ 
    connect(this, SIGNAL( mouseLeftButtonMoved(QPoint)),material_painter_, SLOT(mouseLeftButtonMoved(QPoint)));
    connect(this, SIGNAL( mouseRightButtonRelease()),material_painter_, SLOT(mouseRightButtonRelease()));
}


bool MouseFilter::eventFilter(QObject * obj, QEvent * event){
    if(event->type() == QEvent::MouseMove || event->type() == QEvent::MouseButtonPress){
        if(dynamic_cast<QMouseEvent*>(event)->buttons() == Qt::LeftButton){
            QPoint pos = dynamic_cast<QMouseEvent*>(event)->pos();
            emit mouseLeftButtonMoved(pos);
            return true;
        }
    }
    if(event->type() == QEvent::MouseButtonRelease){
        if(dynamic_cast<QMouseEvent*>(event)->button() == Qt::RightButton){
            emit mouseRightButtonRelease();
            return true;
        }
    }
    return false;

}
