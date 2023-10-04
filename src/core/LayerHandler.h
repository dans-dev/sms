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

class LayerHandler {
public:
    LayerHandler();

    void drawLayer(std::vector<Sprite> layer, SDL_Window* window, SDL_Renderer* renderer, Viewport Viewport);
private:

};

#endif //SMS_LAYERHANDLER_H