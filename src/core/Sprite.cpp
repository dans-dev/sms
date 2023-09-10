#include "Sprite.h"
#include <iostream>

Sprite::Sprite(const char *imagePath, SDL_Renderer *renderer, int x, int y, int w, int h, int rot) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->red = 255;
    this->green = 255;
    this->blue = 255;
    this->rotation = rot;
    this->renderer = renderer;
    this->texture = IMG_LoadTexture(renderer, imagePath);

    SDL_SetTextureBlendMode(texture,  SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(texture, 255);
}

void Sprite::draw(SDL_Renderer *renderer, SDL_Window *window, int cameraX, int cameraY) {
    SDL_SetTextureColorMod(texture, red,green,blue);
    int windowW, windowH;
    SDL_GetWindowSize(window, &windowW, &windowH);
    float scaleW = static_cast<float>(windowW)/5120;
    float scaleH = static_cast<float>(windowH)/2880;

    // Calculate the position of the box
    int boxX = (x+(x-cameraX))*scaleW - (w/2)*scaleW;
    int boxY = (y+(y-cameraY))*scaleH - (h/2)*scaleH;

    SDL_Rect renderRect = {boxX, boxY, static_cast<int>(w*scaleW), static_cast<int>(h*scaleH)};

    SDL_RenderCopyEx(renderer, texture, nullptr, &renderRect, rotation, nullptr, SDL_FLIP_NONE);
}

int Sprite::getX() const {
    return x;
}

void Sprite::setX(int x) {
    this->x = x;
}

int Sprite::getY() const {
    return y;
}

void Sprite::setY(int y) {
    this->y = y;
}

int Sprite::getW() const {
    return w;
}

void Sprite::setW(int w) {
    this->w = w;
}

int Sprite::getH() const {
    return h;
}

void Sprite::setH(int h) {
    this->h = h;
}

int Sprite::getRotation() const {
    return rotation;
}

void Sprite::setRotation(int rotation) {
    this->rotation = rotation;
}

int Sprite::getRed() const {
    return red;
}

void Sprite::setRed(int red) {
    this->red = red;
}

int Sprite::getGreen() const {
    return green;
}

void Sprite::setGreen(int green) {
    this->green = green;
}

int Sprite::getBlue() const {
    return blue;
}

void Sprite::setBlue(int blue) {
    this->blue = blue;
}
