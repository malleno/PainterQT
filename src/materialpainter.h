#pragma once

#include <QObject>
#include <QPoint>
#include "gamescene.h"
#include "materialmodel.h"

class materialPainter : public QObject
{
    Q_OBJECT
public:
    explicit materialPainter(QObject *parent = nullptr, GameScene* = nullptr);
signals:
    void addMaterial(QPoint, MaterialModel::MaterialType);
public slots:
    void mouseLeftButtonMoved(QPoint);
    void mouseRightButtonRelease();

private:
    MaterialModel::MaterialType materialType = MaterialModel::MaterialType::Falling;
    QPoint position;
    GameScene* game_scene_;

    void changeMaterialType();

};

