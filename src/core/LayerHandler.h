/* LayerHandler.h
    Written by JC
    Created on: 04/10/2023
    Purpose: hold method for drawing layers to screen
*/

#ifndef SMS_LAYERHANDLER_H
#define SMS_LAYERHANDLER_H
#include <vector>
#include <SDL_image.h>
#include "Sprite.h"
#include "Viewport.h"
#include "Object.h"

class LayerHandler {
public:
    LayerHandler();

    void drawLayer(std::vector<Sprite> layer, SDL_Window* window, SDL_Renderer* renderer, Viewport viewport) {
        for (int i = 0; i < layer.size(); i++) {
            layer.at(i).draw(renderer, window, viewport.getX(), viewport.getY());
        }
    }
    void drawLayer(std::vector<Object> layer, SDL_Window* window, SDL_Renderer* renderer, Viewport viewport) {
        for (int i = 0; i < layer.size(); i++) {
            layer.at(i).draw(renderer, window, viewport.getX(), viewport.getY());
        }
    }
private:

};

#endif //SMS_LAYERHANDLER_H