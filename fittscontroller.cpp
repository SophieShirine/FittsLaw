#include <iostream>
#include "fittscontroller.h"


FittsController::FittsController(FittsModel *model,QObject *parent) : QObject(parent)
{
    this->m_model = model;
    this->m_mainView = nullptr;
}

void FittsController::updateAValue(int x){
    //m_model->a = x;
    m_mainView->updateAValueLabel(x);
}
void FittsController::updateBValue(int x){
    //m_model->b = x;

}
void FittsController::updateNbTarget(int x){
    //m_model->nbTarget = x;
}
void FittsController::updateMinSize(int x){
    //m_model->minSize = x;
}
void FittsController::updateMaxSze(int x){
    //m_model->maxSize = x;
}
