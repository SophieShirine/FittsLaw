#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "fittsmodel.h"
#include "fittscontroller.h"
#include "experienceview.h"

class FittsModel;
class FittsController;
class ExperienceView;

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
    /*void updateAValueLabel(int x);
    void updateBValueLabel(int x);
    void updateNbTargetLabel(int x);
    void updateMinSizeLabel(int x);
    void updateMaxSizeLabel(int x);*/

private:
    Ui::MainWindow *ui;
    FittsController *m_controller;
    FittsModel *m_model;
    ExperienceView *m_experienceView;

    friend FittsModel;
    friend FittsController;
};
#endif // MAINVIEW_H
