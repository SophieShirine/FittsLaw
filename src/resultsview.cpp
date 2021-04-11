#include "resultsview.h"
#include "ui_resultsview.h"

/**
 * @brief constructor
*/

ResultsView::ResultsView(FittsController *controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultsView)
{
    ui->setupUi(this);
    m_controller = controller;
    plot = new QChartView;
    ui->chartLayout->addWidget(plot);

    setWindowFlag(Qt::FramelessWindowHint);
    setWindowOpacity(0.0);

    //FADE IN ANIMATION
    fadeInAnimation = new QPropertyAnimation( this, "windowOpacity" );
    fadeInAnimation->setDuration( 300 );
    fadeInAnimation->setStartValue( 0.0 );
    fadeInAnimation->setEndValue( 1.0 );

    //CONNECTIONS
    QObject::connect(ui->resultLeaveBtn,SIGNAL(clicked()),m_controller,SLOT(quit()));
    QObject::connect(ui->restartBtn,SIGNAL(clicked()),m_controller,SLOT(backToSettings()));
    QObject::connect(ui->saveBtn,SIGNAL(clicked()),m_controller,SLOT(saveResults()));

}

/**
 * @brief function that launches the fadeInAnimation to allow the results view to
 * appear slowly
 */
void ResultsView::appearing(){
    showFullScreen();
    fadeInAnimation->start();
}

/**
 * @brief display the results previously calculated by the controller
 * @param mean differance, standard deviation, standard error and confidence interval - double
 */
void ResultsView::displayResults(double meanDiff, double sDev, double sErr, double itc) {
    ui->mDiff->setText(QString::number(meanDiff));
    ui->cInt->setText(QString::number(itc));
    ui->sDev->setText(QString::number(sDev));
    ui->sErr->setText(QString::number(sErr));
}

/**
 * @brief destructor
 */
ResultsView::~ResultsView(){delete ui;}
