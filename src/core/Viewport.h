/* Viewport.h
    Written by DN
    Created on: 10/09/2023
    Purpose: Represents a window viewport as an object
*/
#ifndef SMS_VIEWPORT_H
#define SMS_VIEWPORT_H

class Viewport {
public:
    Viewport(int x, int y);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    int getRotation() const;
    void setRotation(int rotation);

private:
    int x;
    int y;
};


#endif //SMS_VIEWPORT_H
