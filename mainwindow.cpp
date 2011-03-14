#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Rame *r = new Rame;
    //r->run();
    Troncon *t1 = new Troncon(10);
    Troncon *t2 = new Troncon(20);
    Ligne *l = new Ligne();
    l->ajouterTroncon(t1);
    l->ajouterTroncon(t2);
    l->afficher();
}

MainWindow::~MainWindow()
{
    delete ui;
}
