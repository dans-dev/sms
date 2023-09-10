#include "PhysicsObject.h"

PhysicsObject::PhysicsObject(const char *image, SDL_Renderer *renderer, SDL_Window *window, int x, int y, int w, int h, int rot) : Object(image, renderer, window, x, y, w, h, rot) {
    this->velocityX = 0;
    this->velocityY = 0;
    this->maxVelocityX = 12;
    this->maxVelocityY = 40;
    this->gravity = 1;
}
bool PhysicsObject::checkCollision(const SDL_Rect& rectA, const SDL_Rect& rectB) {
    if ((rectA.x < rectB.x + rectB.w && rectA.x + rectA.w > rectB.x) and (rectA.y < rectB.y + rectB.h && rectA.y + rectA.h > rectB.y)) {
        return true;
    } else {
        return false;
    }
}

bool PhysicsObject::update(std::vector<Object> checkObjects) {
    bool hasCollidedY = false;

    velocityY += gravity;
    if (velocityY > maxVelocityY) {
        velocityY = maxVelocityY;
    }

    if (velocityX > maxVelocityX) {
        velocityX = maxVelocityX;
    } else if (velocityX < -maxVelocityX) {
        velocityX = -maxVelocityX;
    }

    SDL_Rect textureRectAX = {(x+velocityX)-(hitW/2), y-(hitH/2), hitW, hitH};
    SDL_Rect textureRectAY = {x-(hitW/2), (y+velocityY)-(hitH/2), hitW, hitH};

    for (int i = 0; i < checkObjects.size(); i++) {
        int objX = checkObjects.at(i).getX();
        int objY = checkObjects.at(i).getY();
        int objW = checkObjects.at(i).getHitW();
        int objH = checkObjects.at(i).getHitH();
        SDL_Rect textureRectB = {objX-(objW/2), objY-(objH/2), objW, objH};


        bool collisionResultX = checkCollision(textureRectAX, textureRectB);
        if (collisionResultX) {
            velocityX = 0;
        }
        bool collisionResultY = checkCollision(textureRectAY, textureRectB);
        if (collisionResultY) {
            velocityY = 0;
            if (objY > y) {
                hasCollidedY = true;
            }
        }

        if (collisionResultX and collisionResultY) {
            if (objY > y) {
                y -= 2;
            }
            if (objY < y) {
                y += 2;
            }
        }

    }
    x += velocityX;
    y += velocityY;

    return hasCollidedY;
}