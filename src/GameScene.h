#pragma once

#include "raylib.h"
#include "Scene.h"

class GameScene : public Scene {
public:
    GameScene(int width, int height);
    void Update() override;
    void Draw() override;
    Scene *GetNext() override;

private:
    float _timeSinceLastTick = 0;
    float _timeBetweenTicks = 1;
    bool IsGameOver();
};