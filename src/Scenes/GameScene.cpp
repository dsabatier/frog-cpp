#include "raylib.h"
#include "GameScene.h"
#include "GameOverScene.h"
#include "../Sprites/Car.h"

GameScene::GameScene(int width, int height)
{
    _width = width;
    _height = height;
}

void GameScene::Enter()
{
    _sprites.push_back(new Frog(_width/2, _height - 30));
    _sprites.push_back(new Car(-10, _height - 130, 10, 10, 35));
    _sprites.push_back(new Car(_width + 10, _height - 100, 10, 10, 25));
}

void GameScene::Update()
{
    for(auto & _sprite : _sprites)
    {
        _sprite->Update();
    }
}

void GameScene::Draw()
{
    // background
    DrawRectangle(0, _height - 60, _width, 60, DARKBROWN);
    DrawRectangle(0, _height - 180, _width, 30, DARKBROWN);
    DrawRectangle(0, _height - 220, _width, 70, BLUE);
    DrawRectangle(0, _height - 280, _width, 70, DARKBROWN);

    for(auto & _sprite : _sprites)
    {
        _sprite->Draw();
    }
}

GameState GameScene::GetNext() const
{
    if (IsGameOver()) {
        return GameState::GameOver;
    }

    return GameState::Gameplay;
}

bool GameScene::IsGameOver() const
{
    return false;
}
