/* Sprite.h
    Written by DN
    Created on: 10/09/2023
    Purpose: Represents a drawn element to the screen
*/

#ifndef SMS_SPRITE_H
#define SMS_SPRITE_H
#include <SDL_image.h>

class Sprite {
public:
    Sprite(const char *image, SDL_Renderer *renderer, int x, int y, int w, int h, int rot);
    void draw(SDL_Renderer *renderer, SDL_Window *window, int cameraX, int cameraY);

    int getX() const;
    void setX(int x);
    int getScreenX(int ratioW, int viewportX) const;

    int getY() const;
    void setY(int y);
    int getScreenY(int ratioH, int viewportY) const;

    int getW() const;
    void setW(int w);
    int getScreenW(int ratioW) const;

    int getH() const;
    void setH(int h);
    int getScreenH(int ratioH) const;

    int getRotation() const;
    void setRotation(int rotation);

    int getRed() const;
    void setRed(int red);

    int getGreen() const;
    void setGreen(int green);

    int getBlue() const;
    void setBlue(int blue);


protected:
    SDL_Texture *texture;
    SDL_Renderer *renderer;
    int x;
    int y;
    int w;
    int h;
    int rotation;
    int red;
    int green;
    int blue;
};

#endif //SMS_SPRITE_H
