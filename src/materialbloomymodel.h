#pragma once
#include<materialmodel.h>


class materialBloomyModel : public MaterialModel
{
public:
    enum {Type = 1011010};
    materialBloomyModel(QObject* parent = nullptr);
    void updateThisType(MaterialModel *) override;
    int type() const override;
};

