#pragma once

#include "Sprite.h"
#include "raylib.h"

class Frog : public Sprite {
public:
    Frog(int x, int y);
    void Update() override;
    void Draw() const override;
private:
    Vector2 _position{0,0};

    static Vector2 GetInput();
};