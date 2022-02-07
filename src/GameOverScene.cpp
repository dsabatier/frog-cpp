#include "raylib.h"
#include "GameOverScene.h"
#include "MainMenuScene.h"

GameOverScene::GameOverScene(int width, int height) : Scene(width, height) {
    _timer = 0;
}

void GameOverScene::Update() {
    _timer += GetFrameTime();
}

void GameOverScene::Draw() {
    DrawText("YOU DIED", 12, 60, 24, RED);
}

Scene *GameOverScene::GetNext() {
    Scene* next = this;

    if(_timer >= _waitTime)
    {
        next = new MainMenuScene(_width, _height);
    }

    return next;
}
