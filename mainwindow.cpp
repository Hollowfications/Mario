#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QVector>
#include <fstream>
#include <QPen>
#include <QBrush>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _scene = new QGraphicsScene();

    //this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setAttribute(Qt::WA_TranslucentBackground);


    ui->graphicsView->setScene(_scene);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setAlignment(Qt::AlignBottom|Qt::AlignLeft);
    ui->graphicsView->resize(1600, 800);
    _scene->setSceneRect(0, 0, 1600, 800);


    QPixmap bg("./images/plesen.jpg");
    bg = bg.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Background, bg);
    _scene->setPalette(palette);
    _scene->setBackgroundBrush(*(new QBrush(bg)));

    _hero = new Hero(10);
    _scene->addItem(_hero);
    _hero->setPos(0, 170);
    _scene->setFocusItem(_hero, Qt::OtherFocusReason);
    _scene->addItem(_hero->_heroSprite);

    QVector<QVector<QRect>> map;

    std::fstream file;
    file.open("./maps/lvl1.txt");
    char arr[40][20];
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 40; j++)
            file >> arr[j][i];
    file.close();

    for (int i = 0; i < 40; i++) {
        QVector<QRect> tempVec(20);
        for (int j = 0 ; j < 20; j++) {
            tempVec[j] = QRect(i*40, j*40, 40, 40);
        }
        map.push_back(tempVec);
    }

    QPen pen = Qt::NoPen;
    QBrush brush;

    for (int i = 0; i < 40; i++)
        for (int j = 0; j < 20; j++) {
            if (arr[i][j] == '0') {
                brush = Qt::NoBrush;
                _scene->addRect(map[i][j], pen, brush);
            }
            else if (arr[i][j] == 'g') {
                brush = Qt::Dense3Pattern;
                _scene->addRect(map[i][j], pen, brush);
            }
        }


    _healthLabel1 = new QLabel(this);
    _healthLabel2 = new QLabel(this);
    _healthLabel3 = new QLabel(this);

    QPixmap health("./images/heart.png");
    _healthLabel1->setPixmap(health);
    _healthLabel2->setPixmap(health);
    _healthLabel3->setPixmap(health);

    _healthLabel1->setGeometry(1536, 32, 64, 64);
    _healthLabel2->setGeometry(1472, 32, 64, 64);
    _healthLabel3->setGeometry(1408, 32, 64, 64);


    _timer = new QTimer();
    //connect(_timer, SIGNAL(timeout()), this, SLOT(update()));
    _timer->start(1000/30);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent * event) {
    _hero->keyPressEvent(event);
    ui->graphicsView->mapFromScene(_hero->pos());
    _scene->update();
}

void MainWindow::resizeEvent(QResizeEvent * event) {

}
