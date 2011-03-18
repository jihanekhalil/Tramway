#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rame.h"
#include "ligne.h"
#include "troncon.h"
#include <QPainter>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void afficher();
public slots:
            void loadTime();


private:
    void paintEvent(QPaintEvent *);
    Ui::MainWindow *ui;
    Ligne *l;
    QPixmap pixmap;
    QTimer *timer;
    QPainter * painter;

};

#endif // MAINWINDOW_H
