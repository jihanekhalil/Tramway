#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow), pixmap(QPixmap(100,100))
{
    ui->setupUi(this);
    // creation de la ligne
    this->ligne = new Ligne(100);

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
qDebug() << "test 01";
    // creation et demarrage d'une premiere rame puis association a la ligne
    Rame * r1 = new Rame(this->ligne);

    r1->start();
    this->ligne->ajouterRame(r1);





    // creation du timer
    timer = new QTimer(this);
    timer->setSingleShot(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(loadTime()));
   timer->start(500);



}


void MainWindow::loadTime(){
    update();
    qDebug() << "----------------------------------------------------";
    for(int i= 0; i<this->ligne->getNbRames(); i++)
    {
        this->ligne->getRameAt(i)->avancer();
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{

   QPainter painter(this);
   painter.fillRect(55,0  ,this->width(), 55, QBrush(QColor(255,204,0)));
   painter.fillRect( 0,0  ,50, 55, QBrush(QColor(0,55,166)));
   QFont font(QString("Helvetica"));
   font.setBold(true);
   font.setPixelSize(35);
   painter.setPen(QColor(255,255,255));
   painter.setFont(font);
   painter.drawText(5, 46, "T1");
   painter.setPen(QColor(0,0,0));
   this->ligne->afficher(&painter, this->width(), this->height());


}
void MainWindow::afficher(){
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ligne;
    delete painter;
    delete timer;
}

void MainWindow::on_newRameButton_clicked()
{
    //Ajout d'une rame a la ligne lors du clic sur le bouton
    Rame * r = new Rame(this->ligne);
    r->start();
    this->ligne->ajouterRame(r);
}
