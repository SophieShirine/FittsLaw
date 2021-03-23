#include "resultsview.h"
#include "ui_resultsview.h"

ResultsView::ResultsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultsView)
{
    ui->setupUi(this);
    setVisible(false);

}

ResultsView::~ResultsView()
{
    delete ui;
}
