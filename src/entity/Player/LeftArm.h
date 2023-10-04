#include "BodyPart.h"

#ifndef SMS_LEFTARM_H
#define SMS_LEFTARM_H


class LeftArm : public BodyPart {
public:
    LeftArm(const char *image, SDL_Renderer *renderer, int x, int y, int w, int h, int rot, int rotX, int rotY);
    void update(int x, int y, int velocityX, int velocityY, bool touchingSurface) override;

};


#endif //SMS_LEFTARM_H
