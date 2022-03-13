#include <memory>
#include "raylib.h"
#include "Scenes/MainMenuScene.h"
#include "Scenes/GameScene.h"
#include "Scenes/GameOverScene.h"

int main() {
    // Init
    const int width = 320;
    const int height = 280;

    InitWindow(width, height, "YOU ARE FROG");
    SetTargetFPS(60);

    InitAudioDevice();

    GameState currentState = GameState::MainMenu;
    std::unique_ptr<Scene> currentScene = std::make_unique<MainMenuScene>(width, height);
    currentScene->Enter();

    while (!WindowShouldClose()) {
        GameState nextState = currentScene->GetNext();

        if(nextState != currentState)
        {
            currentScene->Exit();

            currentState = nextState;

            // todo: abstract this
            switch (currentState) {
                case GameState::MainMenu:
                    currentScene = std::make_unique<MainMenuScene>(width, height);
                    break;
                case GameState::Gameplay:
                    currentScene = std::make_unique<GameScene>(width, height);
                    break;
                case GameState::GameOver:
                    currentScene = std::make_unique<GameOverScene>(width, height);
                    break;
            }

            currentScene->Enter();
        }

        currentScene->Update();

        BeginDrawing();
        ClearBackground(BLACK);
        currentScene->Draw();

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}