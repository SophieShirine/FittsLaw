#ifndef EXPERIENCEVIEW_H
#define EXPERIENCEVIEW_H

#include <QDialog>
#include "resultsview.h"
#include "fittscontroller.h"

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
    explicit ExperienceView(QWidget *parent = nullptr);
    ~ExperienceView();

public slots:
    void showExperience();

private:
    Ui::ExperienceView *ui;
    ResultsView *m_resultsView;
    FittsController *m_controller;

    friend ResultsView;
    friend FittsController;
};

#endif // EXPERIENCEVIEW_H
