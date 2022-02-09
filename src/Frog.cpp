#include <cmath>
#include "Frog.h"
#include "raylib.h"
#include "raymath.h"

Frog::Frog(int x, int y) {
    _position.x = floor(x);
    _position.y = floor(y);
}

void Frog::Update() {
    Vector2 input = GetInput();

    _position = Vector2Add(_position, Vector2Scale(input, 10));
}

void Frog::Draw() {
    DrawRectangle(floor(_position.x), floor(_position.y), 10, 10, GREEN);
}

Vector2 Frog::GetInput() {
    Vector2 direction{};

    if(IsKeyPressed(KEY_RIGHT)) direction.x += 1;
    else if(IsKeyPressed(KEY_LEFT)) direction.x -= 1;
    else if(IsKeyPressed(KEY_UP)) direction.y -= 1;
    else if(IsKeyPressed(KEY_DOWN)) direction.y += 1;
    return direction;
}


