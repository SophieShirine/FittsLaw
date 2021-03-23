#include "mainview.h"
#include "ui_mainView.h"

/*
 * main window class, that opens at the beginning of the program
 * allows to set up the parameters for the experience and launch it
*/

MainWiew::MainWiew(QWidget *parent)
    : QMainWindow(parent)
    , mainUi(new Ui::MainWindow)
{
    mainUi->setupUi(this);
    experienceView = new ExperienceView(this);

    QObject::connect(mainUi->pushButton,SIGNAL(clicked()),experienceView,SLOT(showExperience()));

}

MainWiew::~MainWiew()
{
    delete mainUi;
}

