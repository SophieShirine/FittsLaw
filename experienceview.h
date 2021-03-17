#ifndef EXPERIENCEVIEW_H
#define EXPERIENCEVIEW_H

#include <QWidget>

#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>


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
    QPropertyAnimation *mpFadeOut;
    QGraphicsOpacityEffect *op;
};

#endif // EXPERIENCEVIEW_H
