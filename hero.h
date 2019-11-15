#ifndef HERO_H
#define HERO_H

#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QGraphicsScene>
#include "sprite.h"


class Hero : public QObject, public QGraphicsItem {
public:
    Hero(int step);
    int whatUnder();
    int whatUpper();
    int whatRight();
    int whatLeft();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

    int _step;
    bool _nutmeg;
    bool _mushroom;
    int _health;
    int _fire;

    Sprite* _heroSprite;
    QString _imageName;




};

#endif // HERO_H
