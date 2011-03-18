#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow), pixmap(QPixmap(100,100))
{
    ui->setupUi(this);

    this->l = new Ligne(50);
    //this->l->ajouterTroncon(t2);
    Rame * r1 = new Rame(this->l);
   // r1.run();
    this->l->ajouterRame(r1);

    timer = new QTimer(this);
    timer->setSingleShot(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(loadTime()));
    timer->start(100);



}
void MainWindow::loadTime(){
    update();
    QList<Rame *> * rames = this->l->getRames();
    rames->at(0)->avancer();
}

void MainWindow::paintEvent(QPaintEvent *event)
{

   QPainter painter(this);
   this->l->afficher(&painter);

}
void MainWindow::afficher(){
}

MainWindow::~MainWindow()
{
    delete ui;
}
