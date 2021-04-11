#include <iostream>
#include "fittsmodel.h"

/**
 * @brief Constructor
 */
FittsModel::FittsModel(QObject *parent) : QObject(parent)
{
    this->m_mainView = new MainView(this);
}
