#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "experienceview.h"

namespace Ui { class MainWindow; }

class MainWiew : public QMainWindow
{
    Q_OBJECT

public:
    MainWiew(QWidget *parent = nullptr);
    ~MainWiew();

private:
    Ui::MainWindow *mainUi;
    ExperienceView *experienceView;
    //AJOUT LE CONTROLLEUR
    //AJOUT DU MODELE
};
#endif
