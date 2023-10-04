#ifndef SMS_PLAYER_H
#define SMS_PLAYER_H

#include "../../core/Object.h"
#include "LeftArm.h"
#include "RightArm.h"
#include "BodyPart.h"
#include "LeftLeg.h"
#include "RightLeg.h"
#include "Head.h"
#include "Face.h"

class Player : public Object {
public:
    Player(const char *image, SDL_Renderer *renderer, SDL_Window *window, int x, int y, int w, int h, int rot);
    void update(std::vector<Object> checkObjects, int controlInputs[], int cameraX, int cameraY);
    void draw(SDL_Renderer *renderer, SDL_Window *window, int cameraX, int cameraY);
    int getVelocityX();
    int getVelocityY();
    int getDirection();

protected:
    int jumpForce;
    int jumpCounter;
    bool touchingSurface;
    int facingRight;
    int facingTimer;
    // This is so cursed, I don't want to talk about it.
    std::vector<LeftArm> leftArm;
    std::vector<LeftLeg> leftLeg;
    std::vector<RightArm> rightArm;
    std::vector<RightLeg> rightLeg;
    std::vector<Head> playerHead;
    std::vector<Face> playerFace;


};


#endif //SMS_PLAYER_H
