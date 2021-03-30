#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "fittsmodel.h"
#include "fittscontroller.h"
#include "experienceview.h"

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

    void updateAValueLabel(int x);
    void updateBValueLabel(int x);
    void updateNbTargetLabel(int x);
    void updateMinSizeLabel(int x);
    void updateMaxSizeLabel(int x);

public slots:

private:
    Ui::MainWindow *ui;
    FittsController *m_controller;
    FittsModel *m_model;
    ExperienceView *m_experienceView;

    friend FittsModel;
    friend FittsController;
    friend ResultsView;
    friend ExperienceView;
};
#endif // MAINVIEW_H
