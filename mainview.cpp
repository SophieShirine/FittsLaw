#include "mainview.h"
#include "ui_mainView.h"

/*
 * main window class, that opens at the beginning of the program
 * allows to set up the parameters for the experience and launch it
*/

MainView::MainView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->m_model = new FittsModel();

    m_experienceView = new ExperienceView(this);


    QObject::connect(ui->startBtn,SIGNAL(clicked()),m_experienceView,SLOT(showExperience()));

}


MainView::MainView(FittsModel *model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->m_model = model;

    m_experienceView = new ExperienceView(this);

    QObject::connect(ui->startBtn,SIGNAL(clicked()),m_experienceView,SLOT(showExperience()));

    show();
}

MainView::~MainView()
{
    delete ui;
}


/*void MainWiew::updateAValueLabel(){
    QString *value = new QString(ui->aValue->value());
    ui->aValueLabel->setText(*value);
}
void MainWiew::updateBValueLabel(){
    QString *value = new QString(ui->bValue->value());
    ui->bValueLabel->setText(*value);
}
void MainWiew::updateNbTargetLabel(){
    QString *value = new QString(ui->nbTarget->value());
    ui->nbTargetLabel->setText(*value);
}
void MainWiew::updateMinSizeLabel(){
    QString *value = new QString(ui->minSize->value());
    ui->minSizeLabel->setText(*value);
}
void MainWiew::updateMaxSizeLabel(){
    QString *value = new QString(ui->maxSize->value());
    ui->maxSizeLabel->setText(*value);
}
*/

