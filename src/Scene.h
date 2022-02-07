#pragma once

class Scene {
public:
    Scene() = default;

    Scene(int width, int height) : _width(width), _height(height) {

    }

    virtual void Enter()
    {
        // load an initialize
    }

    virtual void Exit()
    {
        // unload and clean up
    }

    virtual void Update() {
        // called every frame before drawing
    }

    virtual void Draw() {
        // draw updated frame
    }

    virtual Scene *GetNext() {
        return nullptr;
    }

protected:
    int _width{};
    int _height{};
};