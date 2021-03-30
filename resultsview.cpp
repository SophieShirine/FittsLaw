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

    //QObject::connect(ui->resultLeaveBtn,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ui->resultLeaveBtn,SIGNAL(clicked()),m_controller,SLOT(backToSettings()));

}


void ResultsView::appearing(){
    showFullScreen();
    fadeInAnimation->start();
}

ResultsView::~ResultsView()
{
    delete ui;
}
