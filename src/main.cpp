/* Main.cpp
    Written by DN
    Created on: 10/09/2023
    Purpose: Main driver of the game, handles logic and brings it all together
*/

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <vector>
#include "core/Object.h"
#include "core/Viewport.h"

int main(int argc, char* args[]) {
    // Frame Controls
    int ticksPerFrame = 1000 / 60; // Number of milliseconds per tick
    int lastTickTime = SDL_GetTicks(); // Get the current time
    bool running = true;


    // SDL Setup
    SDL_Event event;
    SDL_Surface* iconSurface = IMG_Load("assets/core/icon.png");
    SDL_Window* window = SDL_CreateWindow("Steve's Marvellous Sandbox", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
    SDL_SetWindowIcon(window, iconSurface);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Game Settings
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    int playerControls[3] = {SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_SPACE};
    int currentPlayerControls[3];
    Viewport viewport(2560, 1440);

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


        // Handle Quit and Fullscreen
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_F11) {
                    Uint32 flags = SDL_GetWindowFlags(window);
                    if (flags & SDL_WINDOW_FULLSCREEN_DESKTOP) {
                        SDL_SetWindowFullscreen(window, 0);
                    } else {
                        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                    }
                }
            }
        }

        // Logic Loop (Runs at 60 ticks per second)
        while (deltaTime >= ticksPerFrame) {
            deltaTime -= ticksPerFrame;
            lastTickTime += ticksPerFrame;
        }

        // Render Loop
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Draw Objects

        SDL_RenderPresent(renderer);
    }

    // Clean up resources
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}