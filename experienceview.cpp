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
}

void ExperienceView::showExperience(){
    showFullScreen();
}


ExperienceView::~ExperienceView()
{
    delete ui;
}
