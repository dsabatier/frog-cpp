#include "Menu.h"
#include "raymath.h"
#include <iostream>
#include <utility>

Menu::Menu(std::vector<MenuItem> menuItems) : _menuItems(std::move(menuItems)) {}

void Menu::SelectNext() {
    _currentSelection = (_currentSelection + 1) % (int)_menuItems.size();
    printf("Selected: %d \n", _currentSelection);
}

void Menu::SelectPrevious() {
    _currentSelection = abs((_currentSelection - 1) % (int)_menuItems.size());
    printf("Selected: %d \n", _currentSelection);
}

void Menu::Select() const {
    _menuItems[_currentSelection].OnSelect();
}

std::string Menu::GetLabel(int index) const {
    return _menuItems[index].GetText();
}

int Menu::GetItemCount() const {
    return _menuItems.size();
}
