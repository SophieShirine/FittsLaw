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

class FittsController : public QObject
{
    Q_OBJECT
public:
    explicit FittsController(MainView *mainView, FittsModel *model, QObject *parent = nullptr);
    virtual ~FittsController() {}

    ExperienceView* getExpView();
    ResultsView* getResView();

    //void start(); A VOIR SI BESOIN

signals:

public slots:

    void updateAValue(int x); //FAIT
    void updateBValue(int x); //FAIT
    void updateNbTarget(int x); //FAIT
    void updateMinSize(int x); //FAIT
    void updateMaxSize(int x); //FAIT

    void quit(); //FAIT
    void startSimulation(); //FAIT
    void backToSettings(); //FAIT
    void resultClicked(); //A FIGNOLER

    void targetClicked(int x, int y);

private:
    MainView *m_mainView;
    FittsModel *m_model;
    QElapsedTimer *m_timer;

    void initGame(); //FAIT
    void finish(); //FAIT
    void nextTarget();

    void calculateResult();

    friend FittsModel;
};

#endif // FITTSCONTROLLER_H
