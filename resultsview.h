#ifndef RESULTSVIEW_H
#define RESULTSVIEW_H

#include <QDialog>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include "fittscontroller.h"

class FittsModel;
class FittsController;
class ExperienceView;
class MainView;

namespace Ui {
class ResultsView;
}

class ResultsView : public QDialog
{
    Q_OBJECT

public:
    explicit ResultsView(FittsController *controller, QWidget *parent = nullptr);
    ~ResultsView();

public slots:
    void appearing();

private:
    Ui::ResultsView *ui;
    FittsController *m_controller;

    QPropertyAnimation *fadeInAnimation;
    QGraphicsOpacityEffect *opacity;


};

#endif // RESULTSVIEW_H
