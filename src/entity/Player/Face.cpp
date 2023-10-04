#include <cmath>
#include <iostream>
#include "Face.h"

Face::Face(const char *image, SDL_Renderer *renderer, int x, int y, int w, int h, int rot, int rotX, int rotY) : Head(image, renderer, x, y, w, h, rot, rotX, rotY) {
    this->happyFace = IMG_LoadTexture(renderer, "assets/entity/steve/expression/expression_happy.png");
    this->veryHappyFace = IMG_LoadTexture(renderer, "assets/entity/steve/expression/expression_very_happy.png");
}

void Face::update(int x, int y, int velocityX, int velocityY, bool touchingSurface) {
    Head::update(x, y, 0, 0, false);

    if (!touchingSurface) {
        std::cout << "V Happy" << std::endl;
        texture = veryHappyFace;
    } else {
        std::cout << "Happy" << std::endl;
        texture = happyFace;
    }
}
