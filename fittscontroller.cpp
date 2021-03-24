#include "fittscontroller.h"

FittsController::FittsController(QObject *parent) : QObject(parent)
{

}

FittsController::FittsController(FittsModel *model,QObject *parent) : QObject(parent)
{
    this->m_model = model;
}
