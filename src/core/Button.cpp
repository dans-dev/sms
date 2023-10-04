#include "Button.h"
#include <iostream>

Button::Button(const char *image, SDL_Renderer *renderer, SDL_Window *window, int x, int y, int w, int h, int rot) : Sprite(image, renderer, x, y, w, h, rot) {
    this->pressed = false;
}

void Button::press(){
    this->pressed = true;
}

void Button::release(){
    this->pressed = false;
}