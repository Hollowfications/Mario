#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "hero.h"
//#include "platform.h"
#include <QTimer>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;


protected:
    void keyPressEvent(QKeyEvent * event) override;
    void resizeEvent(QResizeEvent * event) override;
public:
    Ui::MainWindow *ui;
    QGraphicsScene *_scene;
    Hero           *_hero;
    //Platform       *_platform;
    QTimer         *_timer;
    QLabel         *_healthLabel1;
    QLabel         *_healthLabel2;
    QLabel         *_healthLabel3;


};

#endif // MAINWINDOW_H
