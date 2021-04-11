#ifndef FITTSCONTROLLER_H
#define FITTSCONTROLLER_H

#include <QObject>
#include "fittsmodel.h"
#include "mainview.h"
#include <QElapsedTimer>

class FittsModel;
class MainView;
class ExperienceView;
class ResultsView;

/*
 * Class of the controller of the program. It has all of the important functions
 * that allows to control both the views and the model.
 */
class FittsController : public QObject
{
    Q_OBJECT
public:
    explicit FittsController(MainView *mainView, FittsModel *model, QObject *parent = nullptr);
    virtual ~FittsController() {}

    ExperienceView* getExpView();
    ResultsView* getResView();

signals:

public slots:

    void updateAValue(int x);
    void updateBValue(int x);
    void updateNbTarget(int x);
    void updateMinSize(int x);
    void updateMaxSize(int x);

    void quit();
    void startSimulation();
    void backToSettings();
    void targetClicked(int x, int y);
    void saveResults();


private:
    MainView *m_mainView;
    FittsModel *m_model;
    QElapsedTimer *m_timer;

    void initGame();
    void finish();
    void nextTarget();
    void calculateResult();

    friend FittsModel;
};

#endif // FITTSCONTROLLER_H
