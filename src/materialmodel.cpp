#include "materialmodel.h"
#include "QPen"

MaterialModel::MaterialModel(QObject* parent, MaterialType type) :
    QObject(parent),
    QGraphicsRectItem(0,0,1,1), //2 px (1 from left and right) for x  and 1016 for y
    type_(type)
{
    setPen(QPen(getMaterialColor()));
    setBrush(QBrush(getMaterialColor()));
}

QColor MaterialModel::getMaterialColor(){
    QString charset { "0123456789abcdef" };
    QString colourHex = "#";
    for(int i =1; i < 7; ++i){
        colourHex.push_back(charset[rand()% 16]);
    }
    return QColor(colourHex);
}

void MaterialModel::updatePosition(){
    if(QRect(0,0,1920,1080).contains(scenePos().toPoint())){
         updateThisType(this);
         return;
    }

    this->~MaterialModel();
}


int MaterialModel::type()const{
    return Type;
}
