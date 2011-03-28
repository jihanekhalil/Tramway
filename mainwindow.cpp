#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow), pixmap(QPixmap(100,100))
{
    ui->setupUi(this);
    // creation de la ligne
    this->ligne = new Ligne(30);

    //Attente
    bool ThreadsLances = true;
    do
    {
        ThreadsLances = true;
        for(int i = 0; i < this->ligne->getListeElement()->size(); i++)
        {
            ThreadsLances = ThreadsLances && this->ligne->getListeElement()->at(i)->getEtatThread();
            qDebug() << "etat " << i << " => " << this->ligne->getListeElement()->at(i)->getEtatThread();
        }
    }while(!ThreadsLances);

    // creation et demarrage d'une premiere rame puis association a la ligne
    Rame * r1 = new Rame(this->ligne);
    r1->start();
    this->ligne->ajouterRame(r1);





    // creation du timer
    timer = new QTimer(this);
    timer->setSingleShot(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(loadTime()));
   timer->start(1500);



}


void MainWindow::loadTime(){
    update();
    qDebug() << "----------------------------------------------------";
    for(int i= 0; i<this->ligne->getNbRames(); i++)
        this->ligne->getRameAt(i)->avancer();
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
    //Ajout d'une rame a la ligne lors du clic sur le bouton
    Rame * r = new Rame(this->ligne);
    r->start();
    this->ligne->ajouterRame(r);
}
