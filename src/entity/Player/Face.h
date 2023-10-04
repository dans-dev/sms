#ifndef SMS_FACE_H
#define SMS_FACE_H


#include "Head.h"

class Face : public Head {
public:
    Face(const char *image, SDL_Renderer *renderer, int x, int y, int w, int h, int rot, int rotX, int rotY);
    void update(int x, int y, int velocityX, int velocityY, bool touchingSurface) override;

private:
    SDL_Texture *happyFace;
    SDL_Texture *veryHappyFace;

};



#endif //SMS_FACE_H
