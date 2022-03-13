#pragma once

#include <functional>

class MenuItem {
public:
    MenuItem(const char* text, std::function<void()> onSelect)
    {
        _text = text;
        OnSelect = std::move(onSelect);
    }

    ~MenuItem(){ printf("deallocated menu item"); }

    const char* GetText() const { return _text; }
    std::function<void()> OnSelect;

private:
    const char* _text;
};

