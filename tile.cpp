#include "tile.h"

Tile::Tile(int x, int y, int w, int h) {
    rectangle = QRect(x, y, width, height);
    width = w;
    height = h;
}


void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawRect(this->x(), this->y(), 40, 40);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Tile::boundingRect() const {
    return QRectF(this->x(), this->y(), 40, 40);
}

Tile Tile::objectOfType(int type) {
    switch (type) {
    case 1: {

        break;
    }
    case 2: {

        break;
    }
    case 3: {

        break;
    }


    }
}
