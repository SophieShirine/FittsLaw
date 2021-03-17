#include "mainview.h"
#include "ui_mainView.h"

/*
 * main window class, that opens at the beginning of the program
 * allows to set up the parameters for the experience and launch it
*/

MainWiew::MainWiew(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWiew::~MainWiew()
{
    delete ui;
}

