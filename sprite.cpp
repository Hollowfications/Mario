#include "sprite.h"

Sprite::Sprite(QObject *parent) :
    QObject(parent), QGraphicsItem() {
    currentFrame = 0;
    _image = new QPixmap();
    _timer = new QTimer();
    //connect(_timer, &QTimer::timeout, this, &Sprite::nextFrame);
    _timer->start(25);
}

Sprite::Sprite(QString name, QPointF point) :
    QObject(), QGraphicsItem() {
    this->setPos(point);
    currentFrame = 0;
    _image = new QPixmap(name);
    _timer = new QTimer();
    //connect(_timer, &QTimer::timeout, this, &Sprite::nextFrame);
    _timer->start(25);
}



QRectF Sprite::boundingRect() const {
    return QRectF(0, 0, 300, 300);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    //painter->drawPixmap(0, 0, *_image, currentFrame, 0, 300,300);
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
}

/*void Sprite::nextFrame() {
    currentFrame += 20;
    if (currentFrame >= 800 ) currentFrame = 0;
    this->update(-10,-10,20,20); // и перерисовываем графический объект с новым кадром спрайта
}
*/
