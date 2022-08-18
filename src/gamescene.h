#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QWidget>
#include <materialmodel.h>


class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QWidget *parent = nullptr);

signals:

public slots:
    void gameSpeedChange(int);
    void nextFrameSlot();
    void addMaterial(QPoint, MaterialModel::MaterialType);
    void addLevelPreset();
private:
    void setupGameLoop();
private:
    QTimer*         gameLoop_;

    void addRectToScene(QPoint, MaterialModel::MaterialType);
};

#endif // GAMESCENE_H
