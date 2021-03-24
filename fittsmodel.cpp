#include "fittsmodel.h"

FittsModel::FittsModel(QObject *parent) : QObject(parent)
{
    this->m_mainView = new MainView(this);
    this->m_controller = new FittsController(this);

    this->m_mainView->m_controller = m_controller;
    this->m_controller->m_mainView = m_mainView;

}
