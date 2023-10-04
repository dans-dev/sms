#ifndef SMS_BODYPART_H
#define SMS_BODYPART_H


#include "../../core/Sprite.h"

class BodyPart : public Sprite{
public:
    BodyPart(const char *image, SDL_Renderer *renderer, int x, int y, int w, int h, int rot, int rotX, int rotY);
    void draw(SDL_Renderer *renderer, SDL_Window *window, int cameraX, int cameraY);
    virtual void update(int x, int y, int velocityX, int velocityY, bool touchingSurface);

protected:
    int rotX;
    int rotY;
    int rDir;
    int rSpd;
    int rMax;
};


#endif //SMS_BODYPART_H
