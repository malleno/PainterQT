#pragma once

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QColor>

class MaterialModel : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    enum {Type = 1000000};
    enum MaterialType {Falling = 0, Bloomy = 1, Static = 2};
    explicit MaterialModel(QObject* parent = nullptr, MaterialType type = MaterialType::Static);
    QColor getMaterialColor();
    virtual int type() const;
    void updatePosition();
    virtual void updateThisType(MaterialModel*) = 0;
signals:
private:
    MaterialType type_;
};

