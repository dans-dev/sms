#include "Viewport.h"

Viewport::Viewport(int x, int y) {
    this->x = x;
    this->y = y;
}

int Viewport::getX() const {
    return this->x;
}

void Viewport::setX(int x) {
    this->x = x;
}

int Viewport::getY() const {
    return this->y;
}

void Viewport::setY(int y) {
    this->y = y;
}
