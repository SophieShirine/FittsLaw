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
    explicit FittsController(QObject *parent = nullptr);
    explicit FittsController(FittsModel *model, QObject *parent = nullptr);

signals:

private:
    MainView *m_mainView;
    FittsModel *m_model;

    friend FittsModel;
};

#endif // FITTSCONTROLLER_H
