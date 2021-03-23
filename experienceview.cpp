#include "experienceview.h"
#include "ui_experienceview.h"

#include <iostream>

ExperienceView::ExperienceView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExperienceView)
{
    ui->setupUi(this);
    //setWindowState(Qt::WindowFullScreen);
    showFullScreen();

    setVisible(false);


    resultsView = new ResultsView(this);

    opacity = new QGraphicsOpacityEffect(this);
    opacity->setOpacity(1.0);
    fadeOutAnimation = new QPropertyAnimation( opacity, "opacity" );
    setGraphicsEffect(opacity);
    fadeOutAnimation->setDuration( 500 );
    fadeOutAnimation->setStartValue( 1.0 );
    fadeOutAnimation->setEndValue( 0.0 );

    QObject::connect(ui->soft,SIGNAL(clicked()),this,SLOT(disappearing()));
}

void ExperienceView::disappearing(){
    fadeOutAnimation->start();
}

ExperienceView::~ExperienceView()
{
    delete ui;
}
