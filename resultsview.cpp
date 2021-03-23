#include "resultsview.h"
#include "ui_resultsview.h"

ResultsView::ResultsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultsView)
{
    ui->setupUi(this);
    setVisible(false);

    opacity = new QGraphicsOpacityEffect(this);
    opacity->setOpacity(0);
    fadeInAnimation = new QPropertyAnimation( opacity, "opacity" );
    setGraphicsEffect(opacity);
    fadeInAnimation->setDuration( 500 );
    fadeInAnimation->setStartValue( 0.0 );
    fadeInAnimation->setEndValue( 1.0 );

}

void ResultsView::appearing(){
    fadeInAnimation->start();
}

ResultsView::~ResultsView()
{
    delete ui;
}
