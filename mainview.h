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
    MainView(QWidget *parent = nullptr);
    MainView(FittsModel *model,QWidget *parent = nullptr);
    ~MainView();

public slots:

private:
    Ui::MainWindow *ui;
    FittsController *m_controller;
    FittsModel *m_model;
    ExperienceView *m_experienceView;

    friend FittsModel;
};
#endif // MAINVIEW_H
