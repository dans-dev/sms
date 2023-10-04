#include <cmath>
#include "Head.h"

Head::Head(const char *image, SDL_Renderer *renderer, int x, int y, int w, int h, int rot, int rotX, int rotY) : BodyPart(image, renderer, x, y, w, h, rot, rotX, rotY) {
    this->rDir = 1;
}

void Head::update(int x, int y, int velocityX, int velocityY, bool touchingSurface) {
    BodyPart::update(x, y, 0, 0, false);

    rMax = abs(round(velocityX / 20)) * 5;

    if (rDir == 1) {
        if (rotation < rDir*rMax) {
            rotation += rDir;
        } else {
            rDir = -rDir;
        }
    } else {
        if (rotation > rDir*rMax) {
            rotation += rDir;
        } else {
            rDir = -rDir;
        }
    }
}