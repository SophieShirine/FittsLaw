#ifndef EXPERIENCEVIEW_H
#define EXPERIENCEVIEW_H

#include <QWidget>

#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

#include "resultsview.h"


namespace Ui { class ExperienceView; }

class ExperienceView : public QWidget
{
    Q_OBJECT

public:
    explicit ExperienceView(QWidget *parent = nullptr);
    ~ExperienceView();

public slots:
    void disappearing();

private:
    Ui::ExperienceView *ui;
    ResultsView *resultsView;

    QPropertyAnimation *fadeOutAnimation;
    QGraphicsOpacityEffect *opacity;
};

#endif // EXPERIENCEVIEW_H
