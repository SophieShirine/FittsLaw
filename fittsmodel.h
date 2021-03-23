#ifndef FITTSMODEL_H
#define FITTSMODEL_H
#include <QPoint>
#include <QList>

class ExperienceView;
class MainView;
class ResultsView;
class FittsController;

class FittsModel
{
public:
    FittsModel();

private:
    MainView *mainView;

    int cibleLeft = 0;
    int nbCible = 10;
    int minSize = 10;
    int maxSize = 150;

    double a = 0.20;
    double b = 0.10;

    double ecartType = 0;
    double erreurType = 0;
    double diffMoy = 0;
    double itc95 = 0;

    QList<QPoint> clickPoints;
    QList<QPoint> cercleCenter;
    QList<int> cercleSize;
    QList<qint64> times;

    friend ExperienceView;
    friend MainView;
    friend ResultsView;
    friend FittsController;
};

#endif // FITTSMODEL_H
