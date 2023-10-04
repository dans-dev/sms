#include "LeftLeg.h"

LeftLeg::LeftLeg(const char *image, SDL_Renderer *renderer, int x, int y, int w, int h, int rot, int rotX, int rotY) : BodyPart(image, renderer, x, y, w, h, rot, rotX, rotY) {
    this->rDir = -1;
}

void LeftLeg::update(int x, int y, int velocityX, int velocityY, bool touchingSurface) {
    BodyPart::update(x+(rotX/2), y+(rotY/2), 0, 0, false);

    rSpd = 2 + bool(abs(velocityX));


    if (touchingSurface) {
        rMax = bool(abs(velocityX)) * 30;

        if (rDir == 1) {
            if (rotation < rDir*rMax) {
                rotation += 2*rSpd*rDir;
            } else {
                rDir = -rDir;
            }
        } else {
            if (rotation > rDir*rMax) {
                rotation += 2*rSpd*rDir;
            } else {
                rDir = -rDir;
            }
        }
    } else {
        rMax = 20;
        if ((abs(rotation) < rMax+5) and (abs(velocityY) > 2)) {
            rotation += 4;
        }
    }

    if (velocityX == 0) {
        if (abs(rotation) <= 3) {
            rotation = 0;
        }
    }

}
