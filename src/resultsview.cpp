#include "resultsview.h"
#include "ui_resultsview.h"


ResultsView::ResultsView(FittsController *controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultsView)
{
    ui->setupUi(this);
    m_controller = controller;
    setWindowFlag(Qt::FramelessWindowHint);
    setWindowOpacity(0.0);

    fadeInAnimation = new QPropertyAnimation( this, "windowOpacity" );
    fadeInAnimation->setDuration( 300 );
    fadeInAnimation->setStartValue( 0.0 );
    fadeInAnimation->setEndValue( 1.0 );

    plot = new QChartView; //CREER UN QCHARTVIEW
    ui->chartLayout->addWidget(plot);
    //resultLayout->addWidget(plot); //AJOUTER AU LAYOUT

    QObject::connect(ui->resultLeaveBtn,SIGNAL(clicked()),m_controller,SLOT(backToSettings()));

}


void ResultsView::appearing(){
    showFullScreen();
    fadeInAnimation->start();
}

void ResultsView::displayResults() {
    //ui->mDiff->setText(QString::number(this->m_model->diffMoy));
    /*this->diffMoy->setText(QString::number(this->fittsModel->diffMoy));
    this->ecartType->setText(QString::number(this->fittsModel->ecartType));
    this->erreurType->setText(QString::number(this->fittsModel->erreurType));
    this->itc95->setText(QString::number(this->fittsModel->itc95));*/
}


ResultsView::~ResultsView()
{
    delete ui;
}
