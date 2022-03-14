#pragma once
#include "Scene.h"
#include "../UI/Menu.h"

class MainMenuScene : public Scene {
public:
    MainMenuScene(int width, int height);

    void Enter() override;
    void Exit() override;
    void Update() override;
    void Draw() override;
    GameState GetNext() const override;

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
    std::unique_ptr<Menu> _menu;

    void Blink();
    void DrawSelectionIndicator() const;
    void DrawMenu() const;
    void DrawTitle() const;
    void Transition();
};

