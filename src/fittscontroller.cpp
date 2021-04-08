#include <iostream>
#include "fittscontroller.h"

#include <QApplication>
#include <iostream>
#include <cmath>
#include <QRandomGenerator>

FittsController::FittsController(MainView *mainView ,FittsModel *model,QObject *parent) : QObject(parent)
{
    this->m_model = model;
    this->m_mainView = mainView;
}

ExperienceView* FittsController::getExpView(){
    return m_mainView->m_experienceView;
}
ResultsView* FittsController::getResView(){
    return m_mainView->m_experienceView->m_resultsView;
}

void FittsController::updateAValue(int x){
    m_model->a = x;
    m_mainView->m_aValueLabel->setText(QString::number(x));
}
void FittsController::updateBValue(int x){
    m_model->b = x;
    m_mainView->m_bValueLabel->setText(QString::number(x));
}
void FittsController::updateNbTarget(int x){
    m_model->nbTarget = x;
    m_mainView->m_nbTargetLabel->setText(QString::number(x));
}
void FittsController::updateMinSize(int x){
    m_model->minSize = x;
    m_mainView->m_minSizeLabel->setText(QString::number(x));

    if(m_mainView->m_maxSizeSlider->value() < 2 * x){
        m_mainView->m_maxSizeSlider->setSliderPosition(2*x);
    }
}
void FittsController::updateMaxSize(int x){
    if(x < m_mainView->m_minSizeSlider->value() * 2 ){
        m_mainView->m_maxSizeSlider->setSliderPosition(m_mainView->m_minSizeSlider->value() * 2 );
        m_model->maxSize = m_mainView->m_minSizeSlider->value() * 2 ;
        m_mainView->m_maxSizeLabel->setText(QString::number(m_mainView->m_minSizeSlider->value() * 2 ));
    }else{
        m_model->maxSize = x;
        m_mainView->m_maxSizeLabel->setText(QString::number(x));
    }

}

void FittsController::startSimulation() {
    this->getExpView()->m_nbTargetsLeft->setText(QString::number(m_model->nbTarget));
    this->getExpView()->showFullScreen();

    this->getExpView()->m_graphicView->setEnabled(true);
    this->m_model->circleSize.clear();
    this->m_model->targetLeft = m_model->nbTarget;
    this->m_model->circleCenter.clear();
    this->m_model->clickPoints.clear();
    this->m_model->times.clear();

    //RESIZE SCENE
    this->getExpView()->m_scene->setSceneRect(0,0,getExpView()->width(),getExpView()->height());
    this->getExpView()->m_graphicView->fitInView(getExpView()->m_scene->sceneRect(),Qt::KeepAspectRatio);

    this->initGame();
}

void FittsController::initGame(){
    getExpView()->m_resultsBtn->setEnabled(false);

    QGraphicsScene *scene = this->getExpView()->m_scene;
    scene->clear();

    if(this->m_model->maxSize >= this->getExpView()->m_graphicView->width() / 2)
        this->m_model->maxSize = this->getExpView()->m_graphicView->width() / 2;

    if(this->m_model->maxSize >= this->getExpView()->m_graphicView->height() / 2)
        this->m_model->maxSize = this->getExpView()->m_graphicView->height() / 2;

    qreal posX = scene->width() / 2;
    qreal posY = scene->height() / 2;
    int size = 100;

    scene->addEllipse(posX - (size / 2), posY - (size / 2), size, size, QPen(QColor("blue")),QBrush(QColor("blue")));
}

void FittsController::targetClicked(int x, int y) {

    if(m_model->circleCenter.isEmpty()){
        //First click set the timer
        m_timer = new QElapsedTimer;
        m_timer->start();

        //add the first target
        m_model->clickPoints.append(QPoint(x,y));
        nextTarget();
    }
    else
    {
        QPointF coords = this->getExpView()->m_graphicView->mapToScene(x,y);
        if(sqrt(pow(coords.x() - this->m_model->circleCenter.last().x(),2) +
                pow(coords.y() - this->m_model->circleCenter.last().y(),2))
                <= this->m_model->circleSize.last() / 2) {
            // We add time to the timer
            this->m_model->times.append(m_timer->elapsed());
            // And restart it
            m_timer->restart();

            // Take the click position
            this->m_model->clickPoints.append(QPoint(x,y));
            this->nextTarget();
        }
    }
}

void FittsController::nextTarget() {
    if(!m_model->circleCenter.isEmpty()){
        m_model->targetLeft--;
        getExpView()->m_nbTargetsLeft->setText(QString::number(m_model->targetLeft));
    }

    QGraphicsScene *scene = getExpView()->m_scene;
    scene->clear();

    //If no more target left, we stop the experience
    if(m_model->targetLeft == 0){
        finish();
        return;
    }

    //Create a red circle
    int size = QRandomGenerator::global()->bounded(this->m_model->minSize,(this->m_model->maxSize + 1) - this->m_model->minSize);

    int sceneW = int(scene->width());
    int sceneH = int(scene->height());

    //METTRE IF AVEC MAX
    qreal posX = QRandomGenerator::global()->bounded(std::min(size,sceneW - size),std::max(size,sceneW - size));
    qreal posY = QRandomGenerator::global()->bounded(std::min(size,sceneH - size),std::max(size,sceneH - size));

    //Stock circle information
    m_model->circleCenter.append(QPoint(int(posX),int(posY)));
    this->m_model->circleSize.append(size);

    //Place the circle
    scene->addEllipse(posX - (size / 2), posY - (size / 2), size, size, QPen(QColor("red")),QBrush(QColor("red")));
}


void FittsController::resultClicked() {
    this->getResView()->appearing();

    //this->calculateResult();
}

void FittsController::quit() {
    QApplication::quit();
}

void FittsController::backToSettings() {
    this->m_mainView->m_experienceView->m_resultsView->close();
    this->m_mainView->m_experienceView->close();
}


void FittsController::finish() {
    this->getExpView()->m_graphicView->setEnabled(false);
    //this->getExpView()->m_graphicView->setBackgroundBrush(QBrush(Qt::white));
    this->getExpView()->m_resultsBtn->setEnabled(true);
}
