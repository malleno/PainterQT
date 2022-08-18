#include "materialstaticmodel.h"

materialStaticModel::materialStaticModel(QObject* parent) :
    MaterialModel(parent, MaterialType::Static)
{
}

void materialStaticModel::updateThisType(MaterialModel *){
}

int materialStaticModel::type()const{
    return Type;
}
