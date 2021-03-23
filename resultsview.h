#ifndef RESULTSVIEW_H
#define RESULTSVIEW_H

#include <QWidget>

#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

namespace Ui {
class ResultsView;
}

class ResultsView : public QWidget
{
    Q_OBJECT

public:
    explicit ResultsView(QWidget *parent = nullptr);
    ~ResultsView();

public slots:
    void appearing();

private:
    Ui::ResultsView *ui;

    QPropertyAnimation *fadeInAnimation;
    QGraphicsOpacityEffect *opacity;
};

#endif // RESULTSVIEW_H
