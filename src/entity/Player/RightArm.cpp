#include "RightArm.h"

RightArm::RightArm(const char *image, SDL_Renderer *renderer, int x, int y, int w, int h, int rot, int rotX, int rotY) : BodyPart(image, renderer, x, y, w, h, rot, rotX, rotY) {
    this->rDir = -1;
}

void RightArm::update(int x, int y, int velocityX, int velocityY, bool touchingSurface) {
    BodyPart::update(x, y, 0, 0, false);

    rSpd = 2 + bool(velocityX);
    if (touchingSurface) {

        rMax = bool(abs(velocityX)) * 20;
        if (rDir == 1) {
            if (rotation < rDir * rMax) {
                rotation += rSpd * rDir;
            } else {
                rDir = -rDir;
            }
        } else {
            if (rotation > rDir * rMax) {
                rotation += rSpd * rDir;
            } else {
                rDir = -rDir;
            }
        }
    } else {
        rMax = 30;
        if ((abs(rotation) < rMax) and (abs(velocityY) > 2)) {
            rotation -= 4;
        }
    }

    if (velocityX == 0) {
        if (abs(rotation) <= 3) {
            rotation = 0;
        }
    }
}
