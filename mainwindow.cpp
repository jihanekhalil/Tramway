/*
 *   Copyright 2011 by Jihane Khalil <khaliljihane@gmail.com>
 *   Copyright 2011 by Paul Labonne <paul.labonne@gmail.com>
 *   Copyright 2011 by Manuel Campomanes <campomanes.manuel@gmail.com>
 *   Copyright 2011 by Marc-Antoine Beauvais <marcantoine.beauvais@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), pixmap(QPixmap(100, 100))
{
    ui->setupUi(this);
    // creation de la ligne
    this->ligne = new Ligne(100);

    //Attente threads tous lances
    bool ThreadsLances = true;
    do {
        ThreadsLances = true;
        for (int i = 0; i < this->ligne->getListeElement()->size(); i++) {
            ThreadsLances = ThreadsLances && this->ligne->getListeElement()->at(i)->getEtatThread();            
        }
    } while (!ThreadsLances);

    // creation et demarrage d'une premiere rame puis association a la ligne
    Rame * r1 = new Rame(this->ligne);

    r1->start();
    this->ligne->ajouterRame(r1);

    this->setWindowState(Qt::WindowMaximized);

    // creation du timer
    timer = new QTimer(this);
    timer->setSingleShot(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(loadTime()));
    timer->start(500);
}


void MainWindow::loadTime()
{
    update();
    qDebug() << "----------------------------------------------------";
    for (int i = 0; i < this->ligne->getNbRames(); i++) {
        this->ligne->getRameAt(i)->avancer();
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.fillRect(55, 0  , this->width(), 55, QBrush(QColor(255, 204, 0)));
    painter.fillRect(0, 0  , 50, 55, QBrush(QColor(0, 55, 166)));
    QFont font(QString("Helvetica"));
    font.setBold(true);
    font.setPixelSize(35);
    painter.setPen(QColor(255, 255, 255));
    painter.setFont(font);
    painter.drawText(5, 40, "T1");
    painter.setPen(QColor(0, 0, 0));
    this->ligne->afficher(&painter, this->width(), this->height());
}
void MainWindow::afficher()
{
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

void MainWindow::on_pushButton_clicked()
{
    this->ligne->ajouterObstacle();
}
