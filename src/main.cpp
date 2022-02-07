#include "raylib.h"
#include "MainMenuScene.h"

int main() {
    // Init
    const int width = 320;
    const int height = 280;

    InitWindow(width, height, "YOU ARE FROG");
    SetTargetFPS(60);

    InitAudioDevice();

    Scene *currentScene = new MainMenuScene(width, height);
    currentScene->Enter();

    while (!WindowShouldClose()) {
        currentScene->Update();

        BeginDrawing();
        ClearBackground(BLACK);
        currentScene->Draw();

        Scene* nextScene = currentScene->GetNext();
        if(nextScene != currentScene)
        {
            currentScene->Exit();
            nextScene->Enter();
        }

        currentScene = nextScene;

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}