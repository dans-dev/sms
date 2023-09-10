/* Object.h
    Written by DN
    Created on: 10/09/2023
    Purpose: Represents a basic object with a square hitbox that is drawn to the screen
*/

#ifndef SMS_OBJECT_H
#define SMS_OBJECT_H
#include "Sprite.h"

class Object : public Sprite {
public:
    Object(const char *image, SDL_Renderer *renderer, SDL_Window *window, int x, int y, int w, int h, int rot);
    void update();
    int getHitW();
    int getHitH();

protected:
    int hitW;
    int hitH;
    SDL_Renderer *renderer;
    SDL_Window *window;

};


#endif //SMS_OBJECT_H
