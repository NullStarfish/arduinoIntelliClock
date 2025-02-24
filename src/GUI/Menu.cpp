#include "Menu.h"

Menu::Menu() {
    selectedIndex = 0;
}

void Menu::addItem(const std::string& item) {
    items.push_back(item);
}

void Menu::selectNext() {
    selectedIndex = (selectedIndex + 1) % items.size();
}

void Menu::selectPrev() {
    selectedIndex = (selectedIndex - 1 + items.size()) % items.size();
}

void Menu::render(Adafruit_SSD1306* display) {
    display->setTextSize(1);
    display->setTextColor(SSD1306_WHITE);
    
    for (int i = 0; i < items.size(); i++) {
        display->setCursor(x, y + i * 10);
        if (i == selectedIndex) {
            display->print("> ");
        }
        display->println(items[i].c_str());
    }
} 