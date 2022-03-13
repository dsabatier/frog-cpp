#pragma once
#include <string>
#include <iostream>
#include "../GameState.h"

class Scene {
public:
    Scene() = default;
    ~Scene() { printf("Scene deallocated"); }

    Scene(int width, int height) : _width(width), _height(height) {
        _width = width;
        _height = height;
    }

    virtual void Enter() {};

    virtual void Exit() {};

    virtual void Update() {};

    virtual void Draw() {}

    virtual GameState GetNext() const {};

protected:
    int _width{0};
    int _height{0};
};