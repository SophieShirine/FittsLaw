#include "fittsmodel.h"
#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator t;

    QStringList languages;
    languages << "English" << "French";

    QString lang = QInputDialog::getItem(NULL,"Select Language","Language",languages);

    if(lang == "French"){
        t.load(":/languages/ResourceFile/french.qm");
    }

    if(lang != "English"){
        a.installTranslator(&t);
    }

    FittsModel model;

    return a.exec();
}
