#include "resultsview.h"
#include "ui_resultsview.h"


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

}


void ResultsView::appearing(){
    showFullScreen();
    fadeInAnimation->start();
}

void ResultsView::displayResults(double meanDiff, double sDev, double sErr, double itc) {
    ui->mDiff->setText(QString::number(meanDiff));
    ui->cInt->setText(QString::number(itc));
    ui->sDev->setText(QString::number(sDev));
    ui->sErr->setText(QString::number(sErr));
}

ResultsView::~ResultsView()
{
    delete ui;
}
