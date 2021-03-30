#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "fittsmodel.h"
#include "fittscontroller.h"
#include "experienceview.h"
#include <QLabel>

class FittsModel;
class FittsController;
class ExperienceView;
class ResultsView;

namespace Ui { class MainWindow; }

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    MainView(FittsModel *model,QWidget *parent = nullptr);
    ~MainView();

public slots:

private:
    Ui::MainWindow *ui;
    FittsController *m_controller;
    FittsModel *m_model;
    ExperienceView *m_experienceView;

    QLabel* m_aValueLabel;
    QLabel* m_bValueLabel;
    QLabel* m_nbTargetLabel;
    QLabel* m_minSizeLabel;
    QLabel* m_maxSizeLabel;

    friend FittsModel;
    friend FittsController;
    friend ResultsView;
    friend ExperienceView;
};
#endif // MAINVIEW_H
