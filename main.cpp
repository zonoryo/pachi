#include <Novice.h>
#include "Ball.h"
#include "Peg.h"
#include <cmath>

const char kWindowTitle[] = "GC2B_06_ドウゾノ_リョウタ";

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    const int kWindowWidth = 800;
    const int kWindowHeight = 600;

    Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    Ball ball(400, 30, 30, 0.0f, 5.0f);
    Peg pegs[15]{
        Peg(100.0f, 200.0f, 10.0f),   // Peg 1 の初期化
        Peg(250.0f, 200.0f, 10.0f),   // Peg 2 の初期化
        Peg(400.0f, 200.0f, 10.0f),   // Peg 3 の初期化
        Peg(550.0f, 200.0f, 10.0f),   // Peg 4 の初期化
        Peg(700.0f, 200.0f, 10.0f),   // Peg 5 の初期化
        Peg(50.0f, 300.0f, 10.0f),    // Peg 6 の初期化
        Peg(200.0f, 300.0f, 10.0f),   // Peg 7 の初期化
        Peg(370.0f, 300.0f, 10.0f),   // Peg 8 の初期化
        Peg(500.0f, 300.0f, 10.0f),   // Peg 9 の初期化
        Peg(650.0f, 300.0f, 10.0f),   // Peg 10 の初期化
        Peg(100.0f, 400.0f, 10.0f),   // Peg 11 の初期化
        Peg(250.0f, 400.0f, 10.0f),   // Peg 12 の初期化
        Peg(400.0f, 400.0f, 10.0f),   // Peg 13 の初期化
        Peg(550.0f, 400.0f, 10.0f),   // Peg 14 の初期化
        Peg(750.0f, 400.0f, 10.0f),   // Peg 15 の初期化
    };

    bool ballLaunched = false;
    float gravity = 0.2f;
    float stay = 5.0f;

    while (Novice::ProcessMessage() == 0) {
        Novice::BeginFrame();

        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        if (keys[DIK_SPACE] && !ballLaunched) {
            ballLaunched = true;
            ball.ballspeedX = 0.0f;
        }

        if (!ballLaunched) {
            ball.ballX += stay;
            if (ball.ballX < 30 || ball.ballX > 770) {
                stay *= -1;
            }
        }
        else {
            ball.ballspeedY += gravity;
            ball.Update();

            for (int i = 0; i < 15; i++) {
                float dx = ball.ballX - pegs[i].pegX;
                float dy = ball.ballY - pegs[i].pegY;
                float distance = std::sqrt(dx * dx + dy * dy);

                if (distance < ball.ballradius + pegs[i].pegradius) {
                    // 釘に当たった場合、反発を無効化
                    // 速度ベクトルを設定してボールを転がす
                    float speed = 2.0f; // 転がる速度を調整
                    if (dx > 0) {
                        ball.ballspeedX = speed;
                    }
                    else {
                        ball.ballspeedX = -speed;
                    }
                    ball.ballspeedY = 0.0f; // 上下の速度をゼロに設定
                }
            }

            // ボールの位置を更新
           // ball.ballX += ball.ballspeedX;
            //ball.ballY += ball.ballspeedY;

            if (ball.ballY > kWindowHeight) {
                ball.ballX = kWindowWidth / 2;
                ball.ballY = 30;
                ball.ballspeedX = 0.0f;
                ball.ballspeedY = 5.0f;
                ballLaunched = false;
            }
        }

        for (int i = 0; i < 15; i++) {
            pegs[i].Draw();
        }

        ball.Draw();

        Novice::EndFrame();

        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }

    Novice::Finalize();
    return 0;
}

