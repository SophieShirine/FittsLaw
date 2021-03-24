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
    explicit FittsController(FittsModel *model, QObject *parent = nullptr);

signals:

public slots:

    void updateAValue(int x);
    void updateBValue(int x);
    void updateNbTarget(int x);
    void updateMinSize(int x);
    void updateMaxSze(int x);


private:
    MainView *m_mainView;
    FittsModel *m_model;

    friend FittsModel;
};

#endif // FITTSCONTROLLER_H
