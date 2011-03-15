#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Rame *r = new Rame;
    //r->run();
    Troncon *t1 = new Troncon(50);
    Troncon *t2 = new Troncon(20);
    this->l = new Ligne();
   this->l->ajouterTroncon(t1);
    //this->l->ajouterTroncon(t2);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
   QPainter painter(this);
   this->pixmap =  QPixmap(100,100);



   this->l->afficher(&painter);
}

MainWindow::~MainWindow()
{
    delete ui;
}
