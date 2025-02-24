#include "src/OS.h"
#include "src/Clock.h"
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define BUTTON_UP    2
#define BUTTON_DOWN  3
#define BUTTON_OK    4
#define BUTTON_BACK  5

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
OS* os;
Clock* clock;

void setup() {
    Wire.begin();
    
    // 初始化操作系统
    os = new OS(&display);
    os->init();
    
    // 创建并添加时钟应用
    clock = new Clock();
    clock->setDisplay(&display);
    os->addApp(clock);
    
    // 后续可以添加更多应用
    
    // 设置按键引脚
    pinMode(BUTTON_UP, INPUT_PULLUP);
    pinMode(BUTTON_DOWN, INPUT_PULLUP);
    pinMode(BUTTON_OK, INPUT_PULLUP);
    pinMode(BUTTON_BACK, INPUT_PULLUP);
}

void loop() {
    // 检测按键输入
    if (digitalRead(BUTTON_UP) == LOW) {
        os->handleInput(1);
    }
    if (digitalRead(BUTTON_DOWN) == LOW) {
        os->handleInput(2);
    }
    if (digitalRead(BUTTON_OK) == LOW) {
        os->handleInput(3);
    }
    if (digitalRead(BUTTON_BACK) == LOW) {
        os->handleInput(4);
    }
    
    os->update();
    os->render();
    delay(16);
}
