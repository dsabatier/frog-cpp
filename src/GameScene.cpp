#include "raylib.h"
#include "GameScene.h"
#include "GameOverScene.h"

GameScene::GameScene(int width, int height) {
    _width = width;
    _height = height;
}

void GameScene::Update() {

}

void GameScene::Draw() {

}

Scene *GameScene::GetNext() {
    if (IsGameOver()) {
        return new GameOverScene(_width, _height);
    }

    return this;
}

bool GameScene::IsGameOver() {
    return false;
}
