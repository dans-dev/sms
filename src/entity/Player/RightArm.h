#include "BodyPart.h"

#ifndef SMS_RIGHTARM_H
#define SMS_RIGHTARM_H


class RightArm : public BodyPart {
public:
    RightArm(const char *image, SDL_Renderer *renderer, int x, int y, int w, int h, int rot, int rotX, int rotY);
    void update(int x, int y, int velocityX, int velocityY, bool touchingSurface) override;

};


#endif //SMS_RIGHTARM_H
