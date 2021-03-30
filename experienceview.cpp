#include "experienceview.h"
#include "ui_experienceview.h"
#include <iostream>

ExperienceView::ExperienceView(FittsController *controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExperienceView)
{
    ui->setupUi(this);


    m_controller = controller;
    m_resultsView = new ResultsView(m_controller,this);
    //m_resultsView = new ResultsView(this);

    QObject::connect(ui->pushButton,SIGNAL(clicked()),this->m_resultsView,SLOT(appearing()));
    QObject::connect(ui->leaveBtn,SIGNAL(clicked()),this,SLOT(close()));
}

ExperienceView::ExperienceView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExperienceView)
{
    ui->setupUi(this);

    m_resultsView = new ResultsView(this);

    QObject::connect(ui->pushButton,SIGNAL(clicked()),this->m_resultsView,SLOT(appearing()));
    QObject::connect(ui->leaveBtn,SIGNAL(clicked()),this,SLOT(close()));
}

void ExperienceView::showExperience(){
    showFullScreen();
}


ExperienceView::~ExperienceView()
{
    delete ui;
}
