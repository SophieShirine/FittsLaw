#include "mainview.h"
#include "ui_mainView.h"

/*
 * main window class, that opens at the beginning of the program
 * allows to set up the parameters for the experience and launch it
*/

MainWiew::MainWiew(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->model = new FittsModel();
    /*BUG*/
    ////this->controller = new FittsController(this, this->model);
    experienceView = new ExperienceView(this);

    show();

    QObject::connect(ui->startBtn,SIGNAL(clicked()),experienceView,SLOT(showExperience()));

}

void MainWiew::updateAValueLabel(){
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

MainWiew::~MainWiew()
{
    delete ui;
}

