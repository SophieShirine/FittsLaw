#include "resultsview.h"
#include "ui_resultsview.h"


ResultsView::ResultsView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultsView)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    setWindowOpacity(0.0);

    fadeInAnimation = new QPropertyAnimation( this, "windowOpacity" );
    fadeInAnimation->setDuration( 300 );
    fadeInAnimation->setStartValue( 0.0 );
    fadeInAnimation->setEndValue( 1.0 );

    QObject::connect(ui->closeButton,SIGNAL(clicked()),this,SLOT(close()));


}

void ResultsView::appearing(){
    showFullScreen();
    fadeInAnimation->start();
}

ResultsView::~ResultsView()
{
    delete ui;
}
