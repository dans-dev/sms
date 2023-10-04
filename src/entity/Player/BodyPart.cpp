#include <iostream>
#include "BodyPart.h"

BodyPart::BodyPart(const char *image, SDL_Renderer *renderer, int x, int y, int w, int h, int rot, int rotX, int rotY) : Sprite(image, renderer, x, y, w, h, rot) {
    this->rotX = rotX; // a real world modifier (eg. 10 units left of center = -10)
    this->rotY = rotY;
}

void BodyPart::update(int x, int y, int i, int i1, bool b) {
    this->x = x;
    this->y = y;
}

void BodyPart::draw(SDL_Renderer *renderer, SDL_Window *window, int cameraX, int cameraY) {
    SDL_SetTextureColorMod(texture, red, green, blue);
    int windowW, windowH;
    SDL_GetWindowSize(window, &windowW, &windowH);
    float scaleW = static_cast<float>(windowW) / 10240;
    float scaleH = static_cast<float>(windowH) / 5760;

    // Calculate the position of the box
    int boxX = (x + (x - cameraX)) * scaleW - (w) * scaleW;
    int boxY = (y + (y - cameraY)) * scaleH - (h) * scaleH;
    //SDL_Point center = {static_cast<int>((x + rotX)+(x + rotX - cameraX) * scaleW), static_cast<int>((y + rotY)+(y + rotY - cameraY) * scaleH)};

    SDL_Point center = {rotX, rotY};

    SDL_Rect renderRect = {boxX, boxY, 2*static_cast<int>(w * scaleW), 2*static_cast<int>(h * scaleH)};
    SDL_RenderCopyEx(renderer, texture, nullptr, &renderRect, rotation, nullptr, SDL_FLIP_NONE);


}