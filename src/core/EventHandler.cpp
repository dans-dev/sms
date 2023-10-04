#include "EventHandler.h"
#include <iostream>
#include <SDL2/SDL.h>

EventHandler::EventHandler(){

}

void EventHandler::eventLoop(SDL_EVENT event){
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
}