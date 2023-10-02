#include <iostream>
#include "Object.h"

Object::Object(const char *image, SDL_Renderer *renderer, SDL_Window *window, int x, int y, int w, int h, int rot) : Sprite(image, renderer, x, y, w, h, rot) {
    this->hitW = w;
    this->hitH = h;
    this->window = window;
}

void Object::update() {}

int Object::getHitW() {
    return this->hitW;
}

int Object::getHitH() {
    return this->hitH;
}
