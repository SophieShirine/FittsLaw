#ifndef FITTSCONTROLLER_H
#define FITTSCONTROLLER_H

#include <QObject>
#include "fittsmodel.h"
#include "mainview.h"

class MainView;
class FittsModel;


class FittsController
{
public:
    FittsController(MainView *MainView, FittsModel *Model);
    virtual ~FittsController() {}

public slots:
    void updateAValueLabel();
    void updateBValueLabel();
    void updateNbTargetLabel();
    void updateMinSizeLabel();
    void updateMaxSizeLabel();

private:
    MainView *mainView;
    FittsModel *model;
};

#endif // FITTSCONTROLLER_H
