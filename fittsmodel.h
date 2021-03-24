#ifndef FITTSMODEL_H
#define FITTSMODEL_H

#include "mainview.h"
#include "fittscontroller.h"
#include <QObject>

class MainView;
class FittsController;

class MainView;

class FittsModel : public QObject
{
    Q_OBJECT
public:
    explicit FittsModel(QObject *parent = nullptr);

signals:

private:
    MainView *m_mainView;
    FittsController *m_controller;

    int targetLeft = 0;
    int nbTarget = 10;
    int minSize = 10;
    int maxSize = 150;

    double a = 0.20;
    double b = 0.10;

    double ecartType = 0;
    double erreurType = 0;
    double diffMoy = 0;
    double itc95 = 0;

    QList<QPoint> clickPoints;
    QList<QPoint> circleCenter;
    QList<int> circleSize;
    QList<qint64> times;

    friend FittsController;

};

#endif // FITTSMODEL_H
