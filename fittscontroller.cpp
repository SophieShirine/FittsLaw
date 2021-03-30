#include <iostream>
#include "fittscontroller.h"

#include <QApplication>

FittsController::FittsController(MainView *mainView ,FittsModel *model,QObject *parent) : QObject(parent)
{
    this->m_model = model;
    this->m_mainView = mainView;
}

void FittsController::updateAValue(int x){
    m_model->a = x;
    m_mainView->updateAValueLabel(x);
}
void FittsController::updateBValue(int x){
    m_model->b = x;
    m_mainView->updateBValueLabel(x);
}
void FittsController::updateNbTarget(int x){
    m_model->nbTarget = x;
    m_mainView->updateNbTargetLabel(x);
}
void FittsController::updateMinSize(int x){
    m_model->minSize = x;
    m_mainView->updateMinSizeLabel(x);
}
void FittsController::updateMaxSize(int x){
    m_model->maxSize = x;
    m_mainView->updateMaxSizeLabel(x);
}

void FittsController::quit() {
    QApplication::quit();
}

void FittsController::backToSettings() {
    this->m_mainView->m_experienceView->m_resultsView->close();
    this->m_mainView->m_experienceView->close();
}
