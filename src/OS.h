#ifndef OS_H
#define OS_H

#include "Clock.h"
#include "Renderable.h"
#include "GUI/Menu.h"
#include <Adafruit_SSD1306.h>
#include <vector>

enum AppType {
    CLOCK_APP,
    MUSIC_APP,
    // 后续可以添加更多应用类型
};

enum OSState {
    MENU_STATE,
    APP_STATE
};

class OS {
private:
    Adafruit_SSD1306* display;
    std::vector<Renderable*> apps;
    int currentAppIndex;
    Menu* mainMenu;
    OSState currentState;

public:
    OS(Adafruit_SSD1306* display);
    void init();
    void switchToNextApp();
    void switchToPrevApp();
    void update();
    void render();
    void addApp(Renderable* app);
    void handleInput(int button);
};

#endif
