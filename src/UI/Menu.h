#pragma once
#include <string>
#include "MenuItem.h"

class Menu {
public:
    explicit Menu(std::vector <MenuItem> menuItems);
    ~Menu() { printf("deallocated menu"); }
    void SelectNext();
    void SelectPrevious();
    void Select() const;
    std::string GetLabel(int index) const;
    int GetItemCount() const;
private:
    std::vector<MenuItem> _menuItems;
    int _currentSelection{0};
};