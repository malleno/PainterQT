#include "materialbloomymodel.h"

materialBloomyModel::materialBloomyModel(QObject* parent) :
    MaterialModel(parent, MaterialType::Bloomy)
{
}

void materialBloomyModel::updateThisType(MaterialModel *){
    QVector<QPoint> diractions {{0,1}, {0, -1}, {-1,0}, {1,0}};
    setPos(pos() + diractions[rand()%4]);
}

int materialBloomyModel::type()const{
    return Type;
}
