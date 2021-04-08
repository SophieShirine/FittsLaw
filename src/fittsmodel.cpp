#include <iostream>
#include "fittsmodel.h"


FittsModel::FittsModel(QObject *parent) : QObject(parent)
{
    this->m_mainView = new MainView(this);


}
