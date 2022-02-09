#pragma once
#include "Scene.h"

class MainMenuScene : public Scene {
public:
    MainMenuScene(int width, int height);
    void Enter() override;
    void Exit() override;
    void Update() override;
    void Draw() override;
    Scene* GetNext() override;

private:
    float _blinkTimer{};
    float _timeBetweenBlinks = 1;
    bool _showPressStartText{};
    bool _transitioning = false;
    float _transitionTimer{};
    float _transitionTime = 2.5;
    bool _goNext = false;
    Music _song{};
    Sound _selectSound{};

    void Blink();
};

