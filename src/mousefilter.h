#pragma once

#include <QObject>
#include "gamescene.h"
#include "materialpainter.h"

class MouseFilter : public QObject
{
    Q_OBJECT
public:
    explicit MouseFilter(QObject *parent = nullptr, GameScene* = nullptr);

signals:
    void mouseLeftButtonMoved(QPoint);
    void mouseRightButtonRelease();
protected:
    virtual bool eventFilter(QObject*, QEvent*);
private:
    materialPainter* material_painter_ = nullptr;
};

