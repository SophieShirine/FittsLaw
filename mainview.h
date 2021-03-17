#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWiew : public QMainWindow
{
    Q_OBJECT

public:
    MainWiew(QWidget *parent = nullptr);
    ~MainWiew();

private:
    Ui::MainWindow *ui;
    //AJOUTER ICI LES DEUX AUTRES FENETRES
    //AJOUT LE CONTROLLEUR
    //AJOUT DU MODELE
};
#endif
