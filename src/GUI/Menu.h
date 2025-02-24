#ifndef MENU_H
#define MENU_H

#include "Component.h"
#include <vector>
#include <string>

class Menu : public Component {
private:
    std::vector<std::string> items;
    int selectedIndex;
    
public:
    Menu();
    void addItem(const std::string& item);
    void selectNext();
    void selectPrev();
    int getSelectedIndex();
    virtual void render(Adafruit_SSD1306* display) override;
};

#endif 