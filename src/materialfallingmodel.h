#pragma once
#include<materialmodel.h>


class materialFallingModel : public MaterialModel
{
public:
    enum {Type = 10101010};
    materialFallingModel(QObject* parent = nullptr);
    void updateThisType(MaterialModel *) override;
    int type() const override;
};

