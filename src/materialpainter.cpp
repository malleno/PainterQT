#include "materialpainter.h"
#include "QTimer"

materialPainter::materialPainter(QObject *parent, GameScene* gamescene) :
    QObject(parent),
    game_scene_(gamescene)
{
    connect(this, SIGNAL(addMaterial(QPoint,MaterialModel::MaterialType )), game_scene_, SLOT(addMaterial(QPoint, MaterialModel::MaterialType)));
}

void materialPainter::mouseLeftButtonMoved(QPoint pos){
    emit addMaterial(pos, materialType);
}

void materialPainter::mouseRightButtonRelease(){
    changeMaterialType();
}

void materialPainter::changeMaterialType(){
    materialType = MaterialModel::MaterialType((materialType + 1)%3 );
}
