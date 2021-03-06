#include "experienceview.h"
#include "ui_experienceview.h"
#include <iostream>

/*
 * Constructor
 */
ExperienceView::ExperienceView(FittsController *controller, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExperienceView)
{
    /////INITIALIZATION
    ui->setupUi(this);
    m_controller = controller;
    m_resultsView = new ResultsView(m_controller,this);
    m_nbTargetsLeft = ui->nbTargetLeftLabel;

    /////GRAPHIC WIDGET SET-UP
    m_graphicView = new GraphicWidget();
    m_graphicView->setBackgroundBrush(QBrush(Qt::white));
    ui->GraphicLayout->addWidget(m_graphicView);
    m_graphicView->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff);
    m_graphicView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_scene = new QGraphicsScene;
    m_graphicView->fitInView(m_scene->sceneRect(),Qt::KeepAspectRatio);
    m_graphicView->setScene(m_scene);
    m_scene->setSceneRect(0,0,m_graphicView->width(),300);

    /////SIGNALS CONNECTIONS
    QObject::connect(ui->leaveBtn,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(m_graphicView, SIGNAL(mouseClicked(int,int)), m_controller, SLOT(targetClicked(int,int)));
}

/*
 * Destructor
 */
ExperienceView::~ExperienceView(){delete ui;}
