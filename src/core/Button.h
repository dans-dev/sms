/* Button.h
    Written by JC
    Created on: 03/10/2023
    Purpose: A clickable UI element to be drawn to the front layer
*/

#ifndef SMS_BUTTON_H
#define SMS_BUTTON_H
#include "Sprite.h"

class Button : public Sprite{
public:
    Button(const char *image, SDL_Renderer *renderer, SDL_Window *window, int x, int y, int w, int h, int rot);
    void press();
    void release();
protected:
    bool pressed;
};

#endif //SMS_BUTTON_H