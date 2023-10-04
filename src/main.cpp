/* Main.cpp
    Written by DN
    Created on: 10/09/2023
    Purpose: Main driver of the game, handles logic and brings it all together
*/

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "core/Object.h"
#include "core/Sprite.h"
#include "core/Viewport.h"
#include "core/Button.h"
#include "core/LayerHandler.h"
#include "entity/Player/Player.h"


int main(int argc, char* args[]) {
    // Frame Controls
    int ticksPerFrame = 1000 / 60; // Number of milliseconds per tick
    int lastTickTime = SDL_GetTicks(); // Get the current time
    int windowW = 1280;
    int windowH = 720;
    int playspaceW = 10240;
    int playspaceH = 5760;
    bool running = true;

    LayerHandler layerHandler;


    // SDL Setup
    SDL_Event event;
    SDL_Surface* iconSurface = IMG_Load("assets/core/icon.png");
    SDL_Window* window = SDL_CreateWindow("Steve's Marvellous Sandbox", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowW, windowH, 0);
    SDL_SetWindowIcon(window, iconSurface);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Game Settings
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    int playerControls[3] = {SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_SPACE};
    int currentPlayerControls[3];
    Viewport viewport(5120, 2880);

    // For in gameplay, render in order. Back for Decor, Mid for Objects, front for Decor (rendered above objects)
    std::vector<Sprite> backLayer;
    std::vector<Object> midLayer;
    std::vector<Sprite> frontLayer;
    std::vector<Sprite> uiLayer;

    // Testing
    Button obj("assets/object/test_block.png", renderer, window, 5120, 2880, 256, 256, 0);
    Player player("assets/entity/steve/body.png", renderer, window, 3000, 2880, 512, 512, 0);
    uiLayer.push_back(obj);

    for (int i = 0; i < 10240; i+= 256) {
        midLayer.push_back(Object("assets/object/test_block.png", renderer, window, i, 3500, 256, 256, 1.0, 0, true));
    }


    // Game loop
    while (running) {
        // Get Keyboard Inputs, Manage Ticks
        const Uint8* keyState = SDL_GetKeyboardState(NULL);
        int currentTime = SDL_GetTicks();
        int deltaTime = currentTime - lastTickTime;

        // get current player controls pressed
        for (int i = 0; i < 3; i++) {
            currentPlayerControls[i] = keyState[playerControls[i]];
        }


        // General Event loop
        while (SDL_PollEvent(&event)) {
            int xClick = 0;
            int yClick = 0;
            switch (event.type) {

                // Handle Quit and Fullscreen
                case SDL_QUIT:
                    running = false;
                    break;

                // Mouse Input reading
                case SDL_MOUSEBUTTONDOWN:
                    xClick = event.button.x * playspaceW/windowW;
                    yClick = event.button.y * playspaceH/windowH;

                    switch (event.button.button){
                         case SDL_BUTTON_LEFT:
                             for (int i = 0; i < uiLayer.size(); i++){
                                int xButton = uiLayer.at(i).getScreenX(playspaceW/windowW, viewport.getX());
                                int yButton = uiLayer.at(i).getScreenY(playspaceH/windowH, viewport.getY());
                                int wButton = uiLayer.at(i).getScreenW(playspaceW/windowW);
                                int hButton = uiLayer.at(i).getScreenH(playspaceH/windowH);

                                if (xClick < xButton + wButton/2 && xClick > xButton - wButton/2) {
                                    if (yClick > yButton - hButton/2 && yClick < yButton + hButton/2) {
                                        uiLayer.at(i).setRed(0);
                                    }
                                }
                             }
                             break;
                        case SDL_BUTTON_RIGHT:
                            break;
                        default:
                            break;
                    }
                    break;

                // Key Input reading
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_F11) {
                        Uint32 flags = SDL_GetWindowFlags(window);
                        if (flags & SDL_WINDOW_FULLSCREEN_DESKTOP) {
                            SDL_SetWindowFullscreen(window, 0);
                        } else {
                            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                        }
                        SDL_GetWindowSize(window, &windowW, &windowH);
                    }
                    break; 
            }
        }
        
        // Render Loop
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Logic Loop (Runs at 60 ticks per second)
        while (deltaTime >= ticksPerFrame) {
            deltaTime -= ticksPerFrame;
            lastTickTime += ticksPerFrame;
            player.update(midLayer, currentPlayerControls, viewport.getX(), viewport.getY());
        }


        // Draw Objects
        layerHandler.drawLayer(midLayer, window, renderer, viewport);
        player.draw(renderer, window, viewport.getX(), viewport.getY());
        layerHandler.drawLayer(uiLayer, window, renderer, viewport);

        SDL_RenderPresent(renderer);
    }

    // Clean up resources
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}