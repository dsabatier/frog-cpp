#include "Menu.h"
#include "raymath.h"
#include <iostream>
#include <utility>

Menu::Menu(std::vector<MenuItem> menuItems) : _menuItems(std::move(menuItems)) {}

void Menu::SelectNext() {
    _currentSelectionIndex = (_currentSelectionIndex + 1) % (int)_menuItems.size();
    printf("Selected: %d \n", _currentSelectionIndex);
}

void Menu::SelectPrevious() {
    _currentSelectionIndex = abs((_currentSelectionIndex - 1) % (int)_menuItems.size());
    printf("Selected: %d \n", _currentSelectionIndex);
}

void Menu::Select() const {
    _menuItems[_currentSelectionIndex].OnSelect();
}

std::string Menu::GetLabel(int index) const {
    return _menuItems[index].GetText();
}

int Menu::GetItemCount() const {
    return _menuItems.size();
}

int Menu::GetSelectionIndex() {
    return _currentSelectionIndex;
}
