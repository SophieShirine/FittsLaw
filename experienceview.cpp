#include "experienceview.h"
#include "ui_experienceview.h"
#include <iostream>

ExperienceView::ExperienceView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExperienceView)
{
    ui->setupUi(this);

    resultsView = new ResultsView;

    QObject::connect(ui->pushButton,SIGNAL(clicked()),this->resultsView,SLOT(appearing()));
    QObject::connect(ui->closeButton,SIGNAL(clicked()),this,SLOT(close()));
}

void ExperienceView::showExperience(){
    showFullScreen();
}


ExperienceView::~ExperienceView()
{
    delete ui;
}
