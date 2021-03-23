#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "experienceview.h"
#include "fittscontroller.h"
#include "fittsmodel.h"

class FittsModel;
class FittsController;

namespace Ui { class MainWindow; }

class MainWiew : public QMainWindow
{
    Q_OBJECT

public:
    MainWiew(QWidget *parent = nullptr);
    ~MainWiew();

public slots:
    void updateAValueLabel();
    void updateBValueLabel();
    void updateNbTargetLabel();
    void updateMinSizeLabel();
    void updateMaxSizeLabel();

private:
    Ui::MainWindow *ui;
    ExperienceView *experienceView;
    FittsController *controller;
    FittsModel *model;
};
#endif
