#ifndef SMS_RIGHTLEG_H
#define SMS_RIGHTLEG_H


#include "BodyPart.h"

class RightLeg : public BodyPart {
public:
    RightLeg(const char *image, SDL_Renderer *renderer, int x, int y, int w, int h, int rot, int rotX, int rotY);
    void update(int x, int y, int velocityX, int velocityY, bool touchingSurface) override;

};



#endif //SMS_RIGHTLEG_H
