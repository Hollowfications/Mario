#ifndef TILE_H
#define TILE_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class Tile: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    enum type {ground, platform, sky};
    explicit Tile(int x, int y, int w, int h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    Tile objectOfType(int type);


    QRect rectangle;
    int width;
    int height;
    int type;
};

#endif // TILE_H
