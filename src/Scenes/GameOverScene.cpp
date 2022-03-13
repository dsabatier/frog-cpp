#include "raylib.h"
#include "GameOverScene.h"

GameOverScene::GameOverScene(int width, int height) : Scene(width, height) {
    _timer = 0;
}

void GameOverScene::Update() {
    _timer += GetFrameTime();
}

void GameOverScene::Draw() {
    DrawText("YOU DIED", 12, 60, 24, RED);
}

GameState GameOverScene::GetNext() const {
    if(_timer >= _waitTime)
    {
        return GameState::MainMenu;
    }

    return GameState::GameOver;
}
