#include "mainview.h"
#include "ui_mainView.h"

/*
 * main window class, that opens at the beginning of the program
 * allows to set up the parameters for the experience and launch it
*/

MainView::MainView(FittsModel *model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->m_model = model;
    this->m_controller = new FittsController(this,model);
    m_model->m_controller = this->m_controller;

    m_experienceView = new ExperienceView(this);

    //ADD A SIGNAL TO TELL THE CONTROLLER THAT THE EXPERIENCE STARTS
    QObject::connect(ui->startBtn,SIGNAL(clicked()),m_experienceView,SLOT(showExperience()));

    QObject::connect(ui->aValue,SIGNAL(valueChanged(int)),this->m_controller,SLOT(updateAValue(int)));
    QObject::connect(ui->bValue,SIGNAL(valueChanged(int)),this->m_controller,SLOT(updateBValue(int)));
    QObject::connect(ui->nbTarget,SIGNAL(valueChanged(int)),this->m_controller,SLOT(updateNbTarget(int)));
    QObject::connect(ui->minSize,SIGNAL(valueChanged(int)),this->m_controller,SLOT(updateMinSize(int)));
    QObject::connect(ui->maxSize,SIGNAL(valueChanged(int)),this->m_controller,SLOT(updateMaxSize(int)));

    QObject::connect(ui->leaveBtn,SIGNAL(clicked()),this,SLOT(close()));

    show();
}


void MainView::updateAValueLabel(int x){
    ui->aValueLabel->setText(QString::number(x));
}
void MainView::updateBValueLabel(int x){
    ui->bValueLabel->setText(QString::number(x));
}
void MainView::updateNbTargetLabel(int x){
    ui->nbTargetLabel->setText(QString::number(x));
}
void MainView::updateMinSizeLabel(int x){
    ui->minSizeLabel->setText(QString::number(x));
}
void MainView::updateMaxSizeLabel(int x){
    ui->maxSizeLabel->setText(QString::number(x));
}

MainView::~MainView()
{
    delete ui;
}



