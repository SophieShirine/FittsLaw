#ifndef EXPERIENCEVIEW_H
#define EXPERIENCEVIEW_H

#include <QDialog>
#include "resultsview.h"

namespace Ui {
class ExperienceView;
}

class ExperienceView : public QDialog
{
    Q_OBJECT

public:
    explicit ExperienceView(QWidget *parent = nullptr);
    ~ExperienceView();

public slots:
    void showExperience();

private:
    Ui::ExperienceView *ui;
    ResultsView *resultsView;

};

#endif // EXPERIENCEVIEW_H
