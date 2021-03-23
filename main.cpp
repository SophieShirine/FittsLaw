//#include "mainview.h"
#include "mainview.h"
#include "fittscontroller.h"
#include "fittsmodel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWiew w;
    w.show();

    //FittsModel *testModel = new FittsModel();

    //FittsController *testController = new FittsController(&w,testModel);

    return a.exec();
}
