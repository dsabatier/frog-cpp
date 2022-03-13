#include "Car.h"

Car::Car(int x, int y, int width, int height, float speed) {
    _position.x = x;
    _position.y = y;
    _size.x = width;
    _size.y = height;
    _speed = speed;

    if(x < 0) _direction = 1; else _direction = -1;
}

void Car::Update() {
    _position.x += _direction * _speed * GetFrameTime();
}

void Car::Draw() const {
    DrawRectangle(_position.x, _position.y, 25, 15, YELLOW);
}


