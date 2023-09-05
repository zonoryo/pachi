#pragma once


class Ball {
public:
    Ball(float x, float y, float radius, float speedX, float speedY);
    void Update();
    void Draw();


    float ballX, ballY;
    float ballradius;
    float ballspeedX, ballspeedY;

private:
  /*  float x, y;
    float radius;
    float speedX, speedY;*/
};

