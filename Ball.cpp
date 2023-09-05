#include "Ball.h"
#include <Novice.h>
#include <cmath>

Ball::Ball(float x, float y, float radius, float speedX, float speedY){
    ballX = x;
    ballY = y;
    ballradius = radius;
    ballspeedX = speedX;
    ballspeedY = speedY;

}

void Ball::Update() {
    ballX += ballspeedX;
    ballY += ballspeedY;
}

void Ball::Draw() {
    Novice::DrawEllipse(static_cast<int>(ballX), static_cast<int>(ballY), static_cast<int>(ballradius), static_cast<int>(ballradius), 1.0f, RED,kFillModeSolid);
}