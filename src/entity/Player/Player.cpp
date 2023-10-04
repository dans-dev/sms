#include "Player.h"

Player::Player(const char *image, SDL_Renderer *renderer, SDL_Window *window, int x, int y, int w, int h, int rot) : Object(image, renderer, window, x, y, w, h, 1.0, rot, false) {
    this->jumpForce = 6;
    this->jumpCounter = 0;
    this->hitbox.clear();
    Point2D p1 = {-40, -170};
    Point2D p2 = {40, -170};
    Point2D p3 = {40, 170};
    Point2D p4 = {-40, 170};
    this->hitbox.push_back(p1);
    this->hitbox.push_back(p2);
    this->hitbox.push_back(p3);
    this->hitbox.push_back(p4);
    this->facingRight = 0;
    this->facingTimer = 0;
    
    LeftArm lArm("assets/entity/steve/arm_left.png", renderer, x, y, w, h, rot, -42, -24);
    this->leftArm.push_back(lArm);
    RightArm rArm("assets/entity/steve/arm_right.png", renderer, x, y, w, h, rot, 42, -24);
    this->rightArm.push_back(rArm);
    LeftLeg lLeg("assets/entity/steve/leg_left.png", renderer, x, y, w, h, rot, 5, 20);
    this->leftLeg.push_back(lLeg);
    RightLeg rLeg("assets/entity/steve/leg_right.png", renderer, x, y, w, h, rot, -5, 20);
    this->rightLeg.push_back(rLeg);
    Head head("assets/entity/steve/head.png", renderer, x, y, w, h, rot, 0, -10);
    this->playerHead.push_back(head);
    Face face("assets/entity/steve/expression/expression_happy.png", renderer, x, y, w, h, rot, 0, -10);
    this->playerFace.push_back(face);
    


}

void Player::update(std::vector<Object> objects, int controlInputs[], int cameraX, int cameraY) {
    if (controlInputs[0]) {
        velocityX -= 1;
    }
    if (controlInputs[1]) {
        velocityX += 1;
    }

    if (touchingSurface) {
        jumpCounter = 0;
    } else {
        if (!controlInputs[2]) {
            jumpCounter = 5;
        }
    }

    if (controlInputs[2]) {
        if (touchingSurface) {
            velocityY -= jumpForce;
        } else {
            if (velocityY < 0 and jumpCounter != 5) {
                velocityY -= jumpForce-jumpCounter;
                jumpCounter += 1;
            }
        }
    }


    if (!controlInputs[0] and !controlInputs[1]) {
        if (touchingSurface) {
            if (velocityX > 0) {
                if (velocityX > 1) {
                    velocityX -= 1;
                }
                velocityX -= 1;
            }
            if (velocityX < 0) {
                if (velocityX < -1) {
                    velocityX += 1;
                }
                velocityX += 1;
            }
        }
    }

    touchingSurface = Object::update(objects);
    
    playerHead.at(0).update(x, y, velocityX, velocityY, touchingSurface);
    rightArm.at(0).update(x, y, velocityX, velocityY, touchingSurface);
    rightLeg.at(0).update(x, y, velocityX, velocityY, touchingSurface);
    leftArm.at(0).update(x, y, velocityX, velocityY, touchingSurface);
    leftLeg.at(0).update(x, y, velocityX, velocityY, touchingSurface);
    playerFace.at(0).update(x + facingRight * 20, y, velocityX, velocityY, touchingSurface);


    if (velocityX < 0) {
        if (facingRight == 1) {
            facingRight = 0;
        } else {
            facingRight = -1;
        }
        facingTimer = 0;
    } else if (velocityX > 0) {
        if (facingRight == -1) {
            facingRight = 0;
        } else {
            facingRight = 1;
        }
        facingTimer = 0;
    } else {
        if (facingTimer == 3) {
            facingRight = 0;
        } else {
            facingTimer += 1;
        }
    }
}

int Player::getDirection() {
    return facingRight;
}

int Player::getVelocityX() {
    return velocityX;
}

int Player::getVelocityY() {
    return velocityY;
}

void Player::draw(SDL_Renderer *renderer, SDL_Window *window, int cameraX, int cameraY) {
    if (facingRight == 1) {
        rightArm.at(0).draw(renderer, window, cameraX, cameraY);
        rightLeg.at(0).draw(renderer, window, cameraX, cameraY);
        Sprite::draw(renderer, window, cameraX, cameraY);
        leftArm.at(0).draw(renderer, window, cameraX, cameraY);
        leftLeg.at(0).draw(renderer, window, cameraX, cameraY);
    } else if (facingRight == -1) {
        leftArm.at(0).draw(renderer, window, cameraX, cameraY);
        leftLeg.at(0).draw(renderer, window, cameraX, cameraY);
        Sprite::draw(renderer, window, cameraX, cameraY);
        rightArm.at(0).draw(renderer, window, cameraX, cameraY);
        rightLeg.at(0).draw(renderer, window, cameraX, cameraY);
    } else {
        rightArm.at(0).draw(renderer, window, cameraX, cameraY);
        rightLeg.at(0).draw(renderer, window, cameraX, cameraY);
        leftArm.at(0).draw(renderer, window, cameraX, cameraY);
        leftLeg.at(0).draw(renderer, window, cameraX, cameraY);
        Sprite::draw(renderer, window, cameraX, cameraY);
    }

    playerHead.at(0).draw(renderer, window, cameraX, cameraY);
    playerFace.at(0).draw(renderer, window, cameraX, cameraY);
}
