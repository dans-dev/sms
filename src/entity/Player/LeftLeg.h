#include "BodyPart.h"

#ifndef SMS_LEFTLEG_H
#define SMS_LEFTLEG_H


class LeftLeg : public BodyPart {
public:
    LeftLeg(const char *image, SDL_Renderer *renderer, int x, int y, int w, int h, int rot, int rotX, int rotY);
    void update(int x, int y, int velocityX, int velocityY, bool touchingSurface) override;

};


#endif //SMS_LEFTLEG_H