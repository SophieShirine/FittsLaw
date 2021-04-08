#ifndef EXPERIENCEVIEW_H
#define EXPERIENCEVIEW_H

#include <QDialog>
#include "resultsview.h"
#include "fittscontroller.h"
#include "graphicwidget.h"
#include <QGraphicsScene>
#include <QLabel>
#include <QPushButton>

class FittsModel;
class FittsController;
class MainView;
class ResultsView;

namespace Ui {
class ExperienceView;
}

class ExperienceView : public QDialog
{
    Q_OBJECT

public:
    explicit ExperienceView(FittsController *controller,QWidget *parent = nullptr);
    ~ExperienceView();

public slots:

private:
    Ui::ExperienceView *ui;
    ResultsView *m_resultsView;
    FittsController *m_controller;

    GraphicWidget *m_graphicView;
    QGraphicsScene *m_scene;

    QLabel *m_nbTargetsLeft;
    QPushButton *m_resultsBtn;

    friend ResultsView;
    friend FittsController;
};

#endif // EXPERIENCEVIEW_H
