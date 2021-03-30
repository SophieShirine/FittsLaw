#include "experienceview.h"
#include "ui_experienceview.h"
#include <iostream>

ExperienceView::ExperienceView(FittsController *controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExperienceView)
{
    /////INITIALIZATION
    ui->setupUi(this);
    m_controller = controller;
    m_resultsView = new ResultsView(m_controller,this);

    /////GRAPHIC WIDGET SET UP
    m_graphicView = new GraphicWidget();
    ui->GraphicLayout->addWidget(m_graphicView);
    m_graphicView->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff);
    m_graphicView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_scene = new QGraphicsScene;
    m_graphicView->fitInView(m_scene->sceneRect(),Qt::KeepAspectRatio);
    m_graphicView->setScene(m_scene);
    m_scene->setSceneRect(0,0,m_graphicView->width(),300);

    /////SIGNALS CONNECTIONS
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
