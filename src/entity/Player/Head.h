#ifndef SMS_HEAD_H
#define SMS_HEAD_H
#include "BodyPart.h"

class Head : public BodyPart {
public:
    Head(const char *image, SDL_Renderer *renderer, int x, int y, int w, int h, int rot, int rotX, int rotY);
    virtual void update(int x, int y, int velocityX, int velocityY, bool touchingSurface) override;

};




#endif //SMS_HEAD_H
