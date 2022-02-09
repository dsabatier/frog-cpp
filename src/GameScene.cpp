#include "raylib.h"
#include "GameScene.h"
#include "GameOverScene.h"
#include "Frog.h"
#include "Car.h"

GameScene::GameScene(int width, int height) {
    _width = width;
    _height = height;
}

void GameScene::Enter() {
    _sprites.push_back(new Frog(_width/2, _height - 30));
    _sprites.push_back(new Car(-10, _height - 130, 10, 10, 35));
    _sprites.push_back(new Car(_width + 10, _height - 100, 10, 10, 25));
}

void GameScene::Update() {
    for(int i = 0; i < _sprites.size(); i++)
    {
        _sprites[i]->Update();
    }
}

void GameScene::Draw() {
    // background
    DrawRectangle(0, _height - 60, _width, 60, BROWN);
    DrawRectangle(0, _height - 180, _width, 30, BROWN);
    DrawRectangle(0, _height - 220, _width, 70, BLUE);
    DrawRectangle(0, _height - 280, _width, 70, BROWN);

    for(int i = 0; i < _sprites.size(); i++)
    {
        _sprites[i]->Draw();
    }
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
