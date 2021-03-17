#include "experienceview.h"
#include "ui_experienceview.h"

#include <iostream>

ExperienceView::ExperienceView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExperienceView)
{
    ui->setupUi(this);
    setVisible(false);

    op = new QGraphicsOpacityEffect(this);
    op->setOpacity(1.0);
    mpFadeOut = new QPropertyAnimation( op, "opacity" );
    setGraphicsEffect(op);
    mpFadeOut->setDuration( 500 );
    mpFadeOut->setStartValue( 1.0 );
    mpFadeOut->setEndValue( 0.0 );

    QObject::connect(ui->soft,SIGNAL(clicked()),this,SLOT(disappearing()));
}

ExperienceView::~ExperienceView()
{
    delete ui;
}

void ExperienceView::disappearing(){
    mpFadeOut->start();
}
