#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow), pixmap(QPixmap(100,100))
{
    ui->setupUi(this);

    this->ligne = new Ligne(50);
    this->rame = new Rame(this->ligne);
    this->rame->start();
   // r1.run();
    this->ligne->ajouterRame(this->rame);

    timer = new QTimer(this);
    timer->setSingleShot(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(loadTime()));
    timer->start(100);



}
void MainWindow::loadTime(){
    update();
    QList<Rame *> * rames = this->ligne->getRames();
    rames->at(0)->avancer();
}

void MainWindow::paintEvent(QPaintEvent *event)
{

   QPainter painter(this);
   this->ligne->afficher(&painter, this->width(), this->height());


}
void MainWindow::afficher(){
}

MainWindow::~MainWindow()
{
    delete ui;
}
