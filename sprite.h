#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QString>

class Sprite : public QObject,  public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Sprite(QObject *parent = nullptr);
    explicit Sprite(QString name, QPointF point);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private slots:
    //void nextFrame();

private:


public:
    QTimer *_timer;
    QPixmap *_image;
    int currentFrame;
};

#endif // SPRITE_H
