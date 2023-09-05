#include "Peg.h"
#include <Novice.h>

Peg::Peg(float x, float y, float radius) {
    pegX = x;
    pegY = y;
    pegradius = radius;

}

void Peg::Draw() {
    Novice::DrawEllipse(static_cast<int>(pegX), static_cast<int>(pegY), static_cast<int>(pegradius), static_cast<int>(pegradius), 1.0f, WHITE, kFillModeSolid);
}