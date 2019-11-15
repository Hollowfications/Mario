#include "hero.h"
#include <QDebug>

Hero::Hero(int step) {
    this->setPos(30, 30);
    _step = step;
    _nutmeg = false;
    _mushroom = false;
    _health = 3;
    _imageName = "./images/ninjatry.png";
    _heroSprite = new Sprite(_imageName, this->pos());
}

void Hero::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_A: {
            this->setPos(this->x() - _step, this->y());
            //_heroSprite->setPos(this->pos());
            break;
        }
        case Qt::Key_D: {
            this->setPos(this->x() + _step, this->y());
            //_heroSprite->setPos(this->pos());
            break;
        }
        case Qt::Key_W: {
            this->setPos(this->x(), this->y() - _step);
            //_heroSprite->setPos(this->pos());
            break;
        }
        case Qt::Key_S: {
            this->setPos(this->x(), this->y() + _step);
            //_heroSprite->setPos(this->pos());
            break;
        }
    }

    if (this->y() < 0) {
        setPos(this->x(), 0);
        _heroSprite->setPos(this->pos());
    }
    else if (this->y() > 170) {
        setPos(this->x(), 170);
        _heroSprite->setPos(this->pos());
    }

    if (this->x() < 0) {
        setPos(0, this->y());
        _heroSprite->setPos(this->pos());
    }
    else if (this->x() > 700) {
        setPos(700, this->y());
        _heroSprite->setPos(this->pos());
    }
}


void Hero::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    return;
}

void Hero::paint(QPainter *painter,
           const QStyleOptionGraphicsItem*option,
           QWidget *widget)
{
   // painter->drawRect(this->x(), this->y(), 10, 10);
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(this->x(),this->y(), *(_heroSprite->_image), _heroSprite->currentFrame, 0, 300, 300);
}

QRectF Hero::boundingRect() const {
    return QRectF(-5, -5, 10, 10);
}

