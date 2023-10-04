#include "LayerHandler.h"
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "Viewport.h"

LayerHandler::LayerHandler() {}

void LayerHandler::drawLayer(std::vector<Sprite> layer, SDL_Window* window, SDL_Renderer* renderer, Viewport viewport) {
    for (int i = 0; i < layer.size(); i++) {
        layer.at(i).draw(renderer, window, viewport.getX(), viewport.getY());
    }
}