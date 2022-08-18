#include "materialfallingmodel.h"
#include "QGraphicsScene"

materialFallingModel::materialFallingModel(QObject* parent) :
    MaterialModel(parent, MaterialType::Falling)
{
}

void materialFallingModel::updateThisType(MaterialModel *){
    setPos(pos() - QPointF(0,-1));
}

int materialFallingModel::type()const{
    return Type;
}
