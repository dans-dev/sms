#include <iostream>
#include "Object.h"

Object::Object(const char *image, SDL_Renderer *renderer, SDL_Window *window, int x, int y, int w, int h, float scale, int rot) : Sprite(image, renderer, x, y, w, h, rot) {
    this->window = window;
    this->renderer = renderer;
    this->scale = scale;
    setW(w*scale);
    setH(h*scale);
    this->isStatic = true;
    this->mass = 0;
    Point2D p1 = {-w/2, -h/2};
    Point2D p2 = {w/2, -h/2};
    Point2D p3 = {w/2, h/2};
    Point2D p4 = {-w/2, h/2};
    this->hitbox.push_back(p1);
    this->hitbox.push_back(p2);
    this->hitbox.push_back(p3);
    this->hitbox.push_back(p4);


}

void Object::update() {
    std::cout << getAdjustedHitbox().at(0).x << " " << getAdjustedHitbox().at(0).y << " - TL Corner" << std::endl;
    std::cout << getAdjustedHitbox().at(1).x << " " << getAdjustedHitbox().at(1).y << " - TR Corner" << std::endl;
    std::cout << getAdjustedHitbox().at(2).x << " " << getAdjustedHitbox().at(2).y << " - BR Corner" << std::endl;
    std::cout << getAdjustedHitbox().at(3).x << " " << getAdjustedHitbox().at(3).y << " - BL Corner" << std::endl;
    std::cout << x << " " << y << " - Object Center" << std::endl << std::endl;
}

Point2D getAdjustedPoint(int pointX, int pointY, int objX, int objY, float scale, int rot) {
    Point2D point;
    float theta = rot*3.14159/180;
    int newX =  static_cast<int>((pointX*cos(theta) - pointY*sin(theta))*scale);
    int newY =  static_cast<int>((pointY*cos(theta) + pointX*sin(theta))*scale);

    point.x = newX+objX;
    point.y = newY+objY;

    return point;
}

// Helper function to subtract two Point2D objects.
Point2D subtract(const Point2D& a, const Point2D& b) {
    return {a.x - b.x, a.y - b.y};
}

// Helper function to calculate the dot product of two points.
int dot(const Point2D& a, const Point2D& b) {
    return a.x * b.x + a.y * b.y;
}

// Helper function to calculate the perpendicular vector of a 2D vector.
Point2D perpendicular(const Point2D& v) {
    return {-v.y, v.x};
}

// Function to project a polygon onto an axis defined by a vector.
std::pair<int, int> projectPolygon(const std::vector<Point2D>& polygon, const Point2D& axis) {
    int minProjection = dot(polygon[0], axis);
    int maxProjection = minProjection;

    for (const Point2D& point : polygon) {
        int projection = dot(point, axis);
        if (projection < minProjection) {
            minProjection = projection;
        }
        if (projection > maxProjection) {
            maxProjection = projection;
        }
    }

    return {minProjection, maxProjection};
}

// Function to check if two polygons intersect.
bool Object::checkCollision(const std::vector<Point2D>& poly1, const std::vector<Point2D>& poly2) {
    for (int i = 0; i < poly1.size(); ++i) {
        int next = (i + 1) % poly1.size();
        Point2D edge = subtract(poly1[next], poly1[i]);
        Point2D axis = perpendicular(edge);

        std::pair<int, int> projection1 = projectPolygon(poly1, axis);
        std::pair<int, int> projection2 = projectPolygon(poly2, axis);

        if (projection1.second < projection2.first || projection2.second < projection1.first) {
            return false; // Found a separating axis
        }
    }

    for (int i = 0; i < poly2.size(); ++i) {
        int next = (i + 1) % poly2.size();
        Point2D edge = subtract(poly2[next], poly2[i]);
        Point2D axis = perpendicular(edge);

        std::pair<int, int> projection1 = projectPolygon(poly1, axis);
        std::pair<int, int> projection2 = projectPolygon(poly2, axis);

        if (projection1.second < projection2.first || projection2.second < projection1.first) {
            return false; // Found a separating axis
        }
    }

    return true; // No separating axis found; polygons intersect
}

std::vector<Point2D> Object::getAdjustedHitbox() {
    std::vector<Point2D> realHitbox;
    
    for (int i = 0; i < hitbox.size(); i++) {
        Point2D tempPoint = getAdjustedPoint(hitbox.at(i).x, hitbox.at(i).y, x, y, scale, rotation);
        realHitbox.push_back(tempPoint);
    }

    return realHitbox;
}

bool Object::getIsStatic() {
    return isStatic;
}