#pragma once
#include "Sprite.h"
#include "raylib.h"

class Car : public Sprite {
public:
    Car() = default;
    Car(int x, int y, int width, int height, float speed);

    void Update() override;
    void Draw() const override;
private:
    Vector2 _position{};
    Vector2 _size{1,1};
    int _direction{};
    float _speed{10};
};
