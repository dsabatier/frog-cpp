#include "raylib.h"
#include "MainMenuScene.h"
#include "GameScene.h"

// todo: add an option to quit, player can select either play or quit

MainMenuScene::MainMenuScene(int width, int height) : Scene(width, height) {

}

void MainMenuScene::Draw() {
    DrawText("YOU ARE", 80, 60, 34, WHITE);
    DrawText("A FROG", 90, 100, 34, GREEN);

    if(_showPressStartText)
        DrawText("press space", 90, 180, 20, WHITE);
    
    if(_transitioning)
    {
        Color color = GetColor(0x000000);
        color = Fade(color, (_transitionTimer / _transitionTime));
        DrawRectangle(0, 0, _width, _height, color);
    }
}

void MainMenuScene::Update() {
    Blink();

    if(!_transitioning && IsKeyPressed(KEY_SPACE))
    {
        _transitioning = true;
        _timeBetweenBlinks = 0.25f;
        PlaySound(_selectSound);
        return;
    }

    if(_transitioning)
        _transitionTimer += GetFrameTime();

    if(_transitionTimer > _transitionTime)
    {
        _goNext = true;
    }

    UpdateMusicStream(_song);
}

Scene *MainMenuScene::GetNext() {
    Scene* next = this;

    if(_goNext)
    {
        next = new GameScene(_width, _height);
    }

    return next;
}

void MainMenuScene::Blink() {
    _blinkTimer += GetFrameTime();

    if(_blinkTimer > _timeBetweenBlinks)
    {
        _blinkTimer -= _timeBetweenBlinks;
        _showPressStartText = !_showPressStartText;
    }
}

void MainMenuScene::Enter() {
    _song = LoadMusicStream(ASSETS_PATH"theme.ogg");
    SetMusicVolume(_song, 0.5f);
    PlayMusicStream(_song);

    _selectSound = LoadSound(ASSETS_PATH"munch.wav");
}

void MainMenuScene::Exit() {
    StopMusicStream(_song);
    UnloadMusicStream(_song);
    UnloadSound(_selectSound);
}
