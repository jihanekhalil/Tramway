#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pixmap = QPixmap(this->width(), this->height());
    this->l = new Ligne(50);
    //this->l->ajouterTroncon(t2);
    Rame * r1 = new Rame(this->l);
    Rame * r2 = new Rame(this->l);
    r2->setPosition(25);
   // r1.run();
    this->l->ajouterRame(r1);

    this->l->ajouterRame(r2);
    timer = new QTimer(this);
    timer->setSingleShot(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(loadTime()));
    timer->start(500);



}
void MainWindow::loadTime(){
    update();
    QList<Rame *> * rames = this->l->getRames();
    for(int i=0; i<rames->size(); i++)
    rames->at(i)->avancer();
}

void MainWindow::paintEvent(QPaintEvent *event)
{

   QPainter painter(this);
   this->l->afficher(&painter, this->width(), this->height());

}
void MainWindow::afficher(){
}

MainWindow::~MainWindow()
{
    delete ui;
}
