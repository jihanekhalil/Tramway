#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD

    this->ligne = new Ligne(50);
    //this->l->ajouterTroncon(t2);
    this->rame = new Rame(this->ligne);
    this->rame->start();
=======
    pixmap = QPixmap(this->width(), this->height());
    this->l = new Ligne(50);
    //this->l->ajouterTroncon(t2);
    Rame * r1 = new Rame(this->l);
    Rame * r2 = new Rame(this->l);
    r2->setPosition(25);
>>>>>>> b17f6908637ec6e1f0fe3e1f19f2e443e40243ce
   // r1.run();
    this->ligne->ajouterRame(this->rame);

    this->l->ajouterRame(r2);
    timer = new QTimer(this);
    timer->setSingleShot(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(loadTime()));
    timer->start(500);



}
void MainWindow::loadTime(){
    update();
<<<<<<< HEAD
    QList<Rame *> * rames = this->ligne->getRames();
    rames->at(0)->avancer();
=======
    QList<Rame *> * rames = this->l->getRames();
    for(int i=0; i<rames->size(); i++)
    rames->at(i)->avancer();
>>>>>>> b17f6908637ec6e1f0fe3e1f19f2e443e40243ce
}

void MainWindow::paintEvent(QPaintEvent *event)
{

   QPainter painter(this);
<<<<<<< HEAD
   this->ligne->afficher(&painter);
=======
   this->l->afficher(&painter, this->width(), this->height());
>>>>>>> b17f6908637ec6e1f0fe3e1f19f2e443e40243ce

}
void MainWindow::afficher(){
}

MainWindow::~MainWindow()
{
    delete ui;
}
