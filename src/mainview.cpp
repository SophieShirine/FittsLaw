#include "mainview.h"
#include "ui_mainView.h"

/**
 * @brief constructor
*/

MainView::MainView(FittsModel *model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->m_model = model;
    this->m_controller = new FittsController(this,model);
    m_model->m_controller = this->m_controller;
    m_experienceView = new ExperienceView(m_controller,this);

    m_aValueLabel = ui->aValueLabel;
    m_bValueLabel = ui->bValueLabel;
    m_nbTargetLabel = ui->nbTargetLabel;
    m_minSizeLabel = ui->minSizeLabel;
    m_maxSizeLabel = ui->maxSizeLabel;
    m_minSizeSlider = ui->minSize;
    m_maxSizeSlider = ui->maxSize;

    m_aValueLabel->setText(QString::number(m_model->a));

    QObject::connect(ui->startBtn,SIGNAL(clicked()),m_controller,SLOT(startSimulation()));
    QObject::connect(ui->aValue,SIGNAL(valueChanged(int)),this->m_controller,SLOT(updateAValue(int)));
    QObject::connect(ui->bValue,SIGNAL(valueChanged(int)),this->m_controller,SLOT(updateBValue(int)));
    QObject::connect(ui->nbTarget,SIGNAL(valueChanged(int)),this->m_controller,SLOT(updateNbTarget(int)));
    QObject::connect(ui->minSize,SIGNAL(valueChanged(int)),this->m_controller,SLOT(updateMinSize(int)));
    QObject::connect(ui->maxSize,SIGNAL(valueChanged(int)),this->m_controller,SLOT(updateMaxSize(int)));

    QObject::connect(ui->leaveBtn,SIGNAL(clicked()),this,SLOT(close())); //has to be changed

    show();
}

/**
 * @brief destructor
 */
MainView::~MainView()
{
    delete ui;
}



