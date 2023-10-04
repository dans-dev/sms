/* Object.h
    Written by DN
    Created on: 10/09/2023
    Purpose: Represents a basic object with a square hitbox that is drawn to the screen
*/

#ifndef SMS_OBJECT_H
#define SMS_OBJECT_H
#include "Sprite.h"
#include <vector>

struct Point2D {
    int x;
    int y;
};

class Object : public Sprite {
public:
    Object(const char *image, SDL_Renderer *renderer, SDL_Window *window, int x, int y, int w, int h, float scale, int rot);
    void update();
    std::vector<Point2D> getHitbox();
    std::vector<Point2D> getAdjustedHitbox();
    bool checkCollision(const std::vector<Point2D> &poly1, const std::vector<Point2D> &poly2);

    bool getIsStatic();

    void setScale(float scale);
    float getScale();

    void setMass(float mass);
    float getMass();


protected:
    SDL_Renderer *renderer;
    SDL_Window *window;
    std::vector<Point2D> hitbox;
    float scale;
    float mass;
    bool isStatic;

};


#endif //SMS_OBJECT_H
