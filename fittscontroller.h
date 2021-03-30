#ifndef FITTSCONTROLLER_H
#define FITTSCONTROLLER_H

#include <QObject>
#include "fittsmodel.h"
#include "mainview.h"

class FittsModel;
class MainView;

class FittsController : public QObject
{
    Q_OBJECT
public:
    explicit FittsController(MainView *mainView, FittsModel *model, QObject *parent = nullptr);
    virtual ~FittsController() {}
    //void start(); A VOIR SI BESOIN

signals:

public slots:

    void updateAValue(int x); //FAIT
    void updateBValue(int x); //FAIT
    void updateNbTarget(int x); //FAIT
    void updateMinSize(int x); //FAIT
    void updateMaxSize(int x); //FAIT

    void quit(); //FAIT
    //void startSimulation();
    void backToSettings();
    //void resultClicked();

    //void targetClicked(int x, int y);

private:
    MainView *m_mainView;
    FittsModel *m_model;

    void initGame();
    void finish();
    void nextTarget();

    void calculateResult();

    friend FittsModel;
};

#endif // FITTSCONTROLLER_H
