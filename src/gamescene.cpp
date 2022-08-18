#include "gamescene.h"
#include "QTimer"
#include "QMouseEvent"
#include "QDebug"
#include <materialfallingmodel.h>
#include <materialstaticmodel.h>
#include <materialbloomymodel.h>

GameScene::GameScene(QWidget *parent) :
    QGraphicsScene(QRectF(0, 0, 1700, 1080), parent),
    gameLoop_(new QTimer())
{
    setItemIndexMethod(GameScene::NoIndex);
    setupGameLoop();

    addLevelPreset();
}



void GameScene::setupGameLoop()
{
    connect(gameLoop_, SIGNAL(timeout()), this, SLOT(nextFrameSlot()));
    gameLoop_-> start(2);
}



void GameScene::nextFrameSlot()
{
    QList<QGraphicsItem*> itemsOnSceneList = this->items();
    for(QGraphicsItem* item : itemsOnSceneList){

        dynamic_cast<MaterialModel*>(item)->updatePosition();
    }
    emit update();
}



void GameScene::gameSpeedChange(int speedFacror)
{
    gameLoop_->setInterval(150 - speedFacror * 10);
}

void GameScene::addRectToScene(QPoint pos, MaterialModel::MaterialType materialType){
    MaterialModel* materialModel = nullptr;
    switch (materialType){
    case MaterialModel::MaterialType::Falling :
        materialModel = new materialFallingModel(this);  //its staic
        break;

    case MaterialModel::MaterialType::Static :
        materialModel = new materialStaticModel(this);
        break;
    case MaterialModel::MaterialType::Bloomy :
        materialModel = new materialBloomyModel(this);
        break;
    }
    materialModel->setPos(pos);
    this->addItem(materialModel);
}


void GameScene::addMaterial(QPoint pos,  MaterialModel::MaterialType materialType){
    addRectToScene(pos, materialType);
}

void GameScene::addLevelPreset(){
    for(int i = 0; i < 100; ++i){
        MaterialModel* materialModel = new materialStaticModel(this);
        materialModel->setPos(QPoint(i,500));
        this->addItem(materialModel);
    }
}
