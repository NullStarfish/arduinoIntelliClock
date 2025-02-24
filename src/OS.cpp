#include "OS.h"

OS::OS(Adafruit_SSD1306* display) {
    this->display = display;
    this->currentAppIndex = 0;
    this->currentState = MENU_STATE;
    
    // 初始化主菜单
    mainMenu = new Menu();
    mainMenu->setPosition(0, 0);
    mainMenu->addItem("Clock");
    mainMenu->addItem("Music");
}

void OS::init() {
    display->begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display->clearDisplay();
    display->display();
}

void OS::handleInput(int button) {
    if (currentState == MENU_STATE) {
        switch (button) {
            case 1: // 上按键
                mainMenu->selectPrev();
                break;
            case 2: // 下按键
                mainMenu->selectNext();
                break;
            case 3: // 确认按键
                currentState = APP_STATE;
                currentAppIndex = mainMenu->getSelectedIndex();
                break;
        }
    } else {
        switch (button) {
            case 4: // 返回按键
                currentState = MENU_STATE;
                break;
        }
    }
}

void OS::render() {
    display->clearDisplay();
    
    if (currentState == MENU_STATE) {
        mainMenu->render(display);
    } else if (currentState == APP_STATE) {
        if (!apps.empty() && apps[currentAppIndex]) {
            apps[currentAppIndex]->render();
        }
    }
    
    display->display();
}

void OS::addApp(Renderable* app) {
    apps.push_back(app);
} 