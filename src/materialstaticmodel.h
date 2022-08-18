#pragma once
#include<materialmodel.h>


class materialStaticModel : public MaterialModel
{
public:
    enum {Type = 100001};
    materialStaticModel(QObject* parent = nullptr);
    void updateThisType(MaterialModel *) override;
    int type() const override;
};

