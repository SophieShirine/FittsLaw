#include <iostream>
#include <string>
#include "fittscontroller.h"
#include <QApplication>
#include <iostream>
#include <cmath>
#include <QRandomGenerator>
#include <QLineSeries>
#include <QCategoryAxis>
#include <QTextStream>
#include <QDir>

/**
 * @brief Constructor
 */
FittsController::FittsController(MainView *mainView ,FittsModel *model,QObject *parent) : QObject(parent),
    m_mainView(mainView), m_model(model) {}

/**
 * @brief Get functions to retrieve the adress of the experience view and the results view,
 * without having to stock them in the controller directly.
 * @return pointer to an experience view or a result view
 */
ExperienceView* FittsController::getExpView(){
    return m_mainView->m_experienceView;
}
ResultsView* FittsController::getResView(){
    return m_mainView->m_experienceView->m_resultsView;
}

/**
 * @brief Functions that updates both the label corresponding to the value,
 * and the value in the model
 * @param value x
 */
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

/**
 * @brief Function that starts the experience. It clears all the previous informations
 * in case the user has already played, and resize the scene to the size of the screen.
 * It then calls the function that inits the game.
 */
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

/**
 * @brief Function that inits the game. It clears the scene from any objects that may
 * have been here before, then add a label that show the user informations.
 */
void FittsController::initGame(){
    QGraphicsScene *scene = this->getExpView()->m_scene;
    scene->clear();

    if(this->m_model->maxSize >= this->getExpView()->m_graphicView->width() / 2)
        this->m_model->maxSize = this->getExpView()->m_graphicView->width() / 2;

    if(this->m_model->maxSize >= this->getExpView()->m_graphicView->height() / 2)
        this->m_model->maxSize = this->getExpView()->m_graphicView->height() / 2;

    //INFO LABEL
    qreal posX = scene->width() / 2;
    qreal posY = scene->height() / 2;

    QLabel *startLabel = new QLabel(tr("Click anywhere on the screen \nto start the simulation !"));
    startLabel->setAlignment(Qt::AlignCenter);
    QString *style = new QString("background-color: rgb(232, 72, 85);color: rgb(255,255,255); font-size:50px;padding: 20px;");
    startLabel->setStyleSheet(*style);
    startLabel->adjustSize();
    startLabel->move(posX-(startLabel->width()/2),posY-(startLabel->height()/2));

    scene->addWidget(startLabel);
}

/**
 * @brief Function called when a click has been made on the graphic widget.
 * It uses the coordinates of the mouse click to predict the behavior of the program.
 * If it's the first click it starts the timer and add the first target.
 * Otherwise, it stores the coordinates of the clic and append the time
 * the user took to clic on the target.
 * It then calls the function nextTarget.
 * @param mouse coordinates
 */
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

/**
 * @brief If there are still targets left, it reduces the number of targets and updates the label.
 * It clears the scene and proceeds to create a new target of random size and random position.
 * It there are no more target left, the game ends.
 */
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

    qreal posX = QRandomGenerator::global()->bounded(std::min(size,sceneW - size),std::max(size,sceneW - size));
    qreal posY = QRandomGenerator::global()->bounded(std::min(size,sceneH - size),std::max(size,sceneH - size));

    //Stock circle information
    m_model->circleCenter.append(QPoint(int(posX),int(posY)));
    this->m_model->circleSize.append(size);

    //Place the circle
    scene->addEllipse(posX - (size / 2), posY - (size / 2), size, size, QPen(QColor("red")),QBrush(QColor("red")));
}

/**
 * @brief calculate the results and show the results view.
 */
void FittsController::finish() {
    this->calculateResult();
    this->getResView()->appearing();
}

/**
 * @brief Calculate the results with the parameters of the experience
 * It creates a chart and stores all the important values in the model
 */
void FittsController::calculateResult(){
    //CHART DISPLAY
    QChart *chart = new QChart;
    this->getResView()->plot->setChart(chart);
    this->getResView()->plot->setRenderHint(QPainter::Antialiasing);

    //chart->setTitle("Fitts Law Results");
    chart->setTitle(tr("Fitts Law Results"));
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->createDefaultAxes();
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QLineSeries *expSeries = new QLineSeries;
    //expSeries->setName("Experimental curve");
    expSeries->setName(tr("Experimental curve"));
    QLineSeries *fittsSeries = new QLineSeries;
    //fittsSeries->setName("Theoritical curve");
    fittsSeries->setName(tr("Theoritical curve"));
    QCategoryAxis *axis = new QCategoryAxis;

    QList<double> fittsValues;

    for(int i = 0; i < this->m_model->nbTarget; ++i) {
        double T = this->m_model->times[i];
        expSeries->append(i,T);
        double D = sqrt(pow(this->m_model->clickPoints[i].x() - this->m_model->circleCenter[i].x(),2) + pow(this->m_model->clickPoints[i].y() - this->m_model->circleCenter[i].y(),2));

        // On multiplie par 100 pour être en ms
        double value = (this->m_model->a * 1000) + ((this->m_model->b * 1000) * log2((D / this->m_model->circleSize[i]) + 1));
        fittsValues.append(value);
        fittsSeries->append(i,value);

        axis->append(QString::number(i + 1) + "<br />T: "+QString::number(T)+"<br />D: " + QString::number(D),i);
    }

    axis->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);

    chart->addSeries(expSeries);
    chart->addSeries(fittsSeries);

    chart->setAxisX(axis,expSeries);
    chart->setAxisX(axis,fittsSeries);

    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText(tr("time (in ms)"));
    //axisY->setTitleText("temps (en ms)");
    chart->setAxisY(axisY,expSeries);

    //STATS

    /**Averages**/
    QList<double> diffValues;
    double diffMoy = 0;

    for (int i = 0; i < fittsValues.size(); ++i) {
        diffValues.append(fabs(fittsValues[i] - this->m_model->times[i]));
        diffMoy += fabs(fittsValues[i] - this->m_model->times[i]);
    }
    diffMoy /= fittsValues.size();

    // stock mean differance
    this->m_model->diffMoy = fabs(diffMoy);

    /**standard deviation**/
    double variance = 0;

    for (int i = 0; i < fittsValues.size(); ++i) {
        variance += pow(diffValues[i] - diffMoy,2);
    }
    variance /= fittsValues.size();

    double ecartType = sqrt(variance);

    // stock standard deviation
    this->m_model->ecartType = ecartType;
    // stock standard error
    this->m_model->erreurType = fabs(ecartType / sqrt(fittsValues.size()));
    // stock itc 95%
    this->m_model->itc95 = 2 * this->m_model->erreurType;

    this->getResView()->displayResults(m_model->diffMoy,m_model->ecartType,m_model->erreurType,m_model->itc95);

}

/**
 * @brief when the user chooses to export the results, it
 * creates a text file and stores the results in it.
 * The functions count the number of files already present in the
 * results files, and add that number to the name of the file to avoid similarities.
 */
void FittsController::saveResults(){
    QDir *resultDir = new QDir("../FittsLaw/results");
    resultDir->setFilter( QDir::AllEntries | QDir::NoDotAndDotDot );
    int nbFiles = resultDir->count();

    QString *path = new QString("../FittsLaw/results/results");
    path->append(QString::number(nbFiles));
    path->append(".txt");
    QFile *resultFile = new QFile(*path);
    resultFile->open(QIODevice::WriteOnly);

    QTextStream flux(resultFile);
    flux.setCodec("UTF-8");

    flux << tr("Experience results :\n\nMean difference = ") << m_model->diffMoy << tr("\nStandard variation = ")<< m_model->ecartType
             <<  tr("\nStandard error = ")<< m_model->erreurType << tr("\nConfidence interval = ") << m_model->itc95 ;
   resultFile->close();
}

/**
 * @brief quit the application
 */
void FittsController::quit() {
    QApplication::quit();
}

/**
 * @brief close the other windows and direct the user to the main view.
 */
void FittsController::backToSettings() {
    this->m_mainView->m_experienceView->m_resultsView->close();
    this->m_mainView->m_experienceView->close();
}
