#ifndef RESULTSVIEW_H
#define RESULTSVIEW_H

#include <QChartView>
#include <QDialog>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include "fittscontroller.h"

QT_CHARTS_USE_NAMESPACE

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
    void appearing();
    void displayResults();

public slots:

private:
    Ui::ResultsView *ui;
    FittsController *m_controller;

    QChartView *plot;

    QPropertyAnimation *fadeInAnimation;
    QGraphicsOpacityEffect *opacity;



};

#endif // RESULTSVIEW_H
