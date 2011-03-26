#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow), pixmap(QPixmap(100,100))
{
    ui->setupUi(this);

    this->ligne = new Ligne(100);
    Rame * r1 = new Rame(this->ligne);
    r1->start();
    this->ligne->ajouterRame(r1);






    timer = new QTimer(this);
    timer->setSingleShot(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(loadTime()));
    timer->start(1500);



}
void MainWindow::loadTime(){
    update();
    qDebug() << "----------------------------------------------------";
    QList<Rame *> * rames = this->ligne->getRames();
    for(int i= 0; i<rames->size(); i++)
    rames->at(i)->avancer();
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

void MainWindow::on_newRameButton_clicked()
{
    Rame * r = new Rame(this->ligne);
    r->start();
    this->ligne->ajouterRame(r);
}
