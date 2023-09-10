/* PhysicsObject.h
    Written by DN
    Created on: 10/09/2023
    Purpose: Represents a basic object that is also affected by gravity and other physics properties
*/

#ifndef SMS_PHYSICSOBJECT_H
#define SMS_PHYSICSOBJECT_H
#include "Object.h"
#include <vector>

class PhysicsObject : public Object {
public:
    PhysicsObject(const char *image, SDL_Renderer *renderer, SDL_Window *window, int x, int y, int w, int h, int rot);
    bool update(std::vector<Object> checkObjects);
    bool checkCollision(const SDL_Rect& rectA, const SDL_Rect& rectB);


protected:
    int gravity;
    int maxVelocityX;
    int velocityY;
    int maxVelocityY;
    int velocityX;
};


#endif //SMS_PHYSICSOBJECT_H
