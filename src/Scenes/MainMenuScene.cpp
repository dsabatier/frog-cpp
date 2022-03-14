#include <memory>
#include "raylib.h"
#include "MainMenuScene.h"
#include "GameScene.h"

MainMenuScene::MainMenuScene(int width, int height) : Scene(width, height) {
    MenuItem startGame = MenuItem("start", [&]() {
        _transitioning = true;
        PlaySound(_selectSound);
    });

    MenuItem quitGame = MenuItem("quit", [&]() {
        CloseWindow();
    });

    std::vector<MenuItem> menuItems = std::vector<MenuItem>();
    menuItems.push_back(startGame);
    menuItems.push_back(quitGame);

    _menu = std::make_unique<Menu>(menuItems);
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
    Scene::Exit();
}

void MainMenuScene::Update() {


    if(IsKeyPressed(KEY_DOWN))
    {
        _menu->SelectNext();
    }
    else if(IsKeyPressed(KEY_UP))
    {
        _menu->SelectPrevious();
    }

    if(IsKeyPressed(KEY_ENTER))
    {
        _menu->Select();
        return;
    }

    Blink();
    Transition();

    UpdateMusicStream(_song);
}

void MainMenuScene::Transition() {
    if(_transitioning)
    {
        _timeBetweenBlinks = 0.25f;
        _transitionTimer += GetFrameTime();
    }

    if(_transitionTimer > _transitionTime)
    {
        _goNext = true;
    }
}

void MainMenuScene::Draw() {
    DrawTitle();
    DrawMenu();

    if(_transitioning)
    {
        Color color = GetColor(0x000000);
        color = Fade(color, (_transitionTimer / _transitionTime));
        DrawRectangle(0, 0, _width, _height, color);
    }
}

void MainMenuScene::DrawTitle() const {
    DrawText("YOU ARE", 95, 60, 34, WHITE);
    DrawText("A FROG", 105, 100, 34, GREEN);
}

void MainMenuScene::DrawMenu() const {
    DrawSelectionIndicator();
    int itemCount{_menu->GetItemCount()};
    int topX{180};
    int spacing{20};

    for(int i{0}; i < itemCount; i++)
    {
        DrawText(_menu->GetLabel(i).c_str(), 145, topX + (i*spacing), 20, WHITE);
    }
}

void MainMenuScene::DrawSelectionIndicator() const {

    float offset{20 * (float)_menu->GetSelectionIndex()};
    if(_showPressStartText)
    {
        DrawTriangle(
                Vector2{140, 188 + offset},
                Vector2{135, 182 + offset},
                Vector2{135, 192 + offset}, WHITE);
    }

}

GameState MainMenuScene::GetNext() const {
    if(_goNext)
    {
        return GameState::Gameplay;
    }

    return GameState::MainMenu;
}

void MainMenuScene::Blink() {
    _blinkTimer += GetFrameTime();

    if(_blinkTimer > _timeBetweenBlinks)
    {
        _blinkTimer -= _timeBetweenBlinks;
        _showPressStartText = !_showPressStartText;
    }
}


