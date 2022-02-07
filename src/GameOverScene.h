#pragma once
#include "Scene.h"


class GameOverScene : public Scene {
public:
    GameOverScene(int width, int height);

    void Update() override;
    void Draw() override;
    Scene* GetNext() override;

private:
    float _timer;
    float _waitTime = 3.0f;
};
