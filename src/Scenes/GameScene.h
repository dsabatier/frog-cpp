#pragma once

#include <vector>
#include "raylib.h"
#include "Scene.h"
#include "../Sprites/Frog.h"

class GameScene : public Scene {
public:
    GameScene(int width, int height);

    void Enter() override;
    void Update() override;
    void Draw() override;
    GameState GetNext() const override;

private:
    float _timeSinceLastTick = 0;
    float _timeBetweenTicks = 1;
    std::vector<Sprite*>(_sprites){};
    bool IsGameOver() const;
};