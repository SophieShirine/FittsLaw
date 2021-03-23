#ifndef RESULTSVIEW_H
#define RESULTSVIEW_H

#include <QWidget>

namespace Ui {
class ResultsView;
}

class ResultsView : public QWidget
{
    Q_OBJECT

public:
    explicit ResultsView(QWidget *parent = nullptr);
    ~ResultsView();

private:
    Ui::ResultsView *ui;
};

#endif // RESULTSVIEW_H
