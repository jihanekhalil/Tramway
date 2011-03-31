#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rame.h"
#include "ligne.h"
#include <QPainter>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    void afficher();

public slots:
    void loadTime();

private:
    void paintEvent(QPaintEvent *);

    Ligne * ligne;
    QPixmap pixmap;
    QTimer * timer;
    QPainter * painter;

    Ui::MainWindow *ui;

private slots:
    void on_pushButton_clicked();
    void on_newRameButton_clicked();
};

#endif // MAINWINDOW_H
