#include "Clock.h"
#include <Adafruit_SSD1306.h>

Clock::Clock() {
    hour = 0;
    minute = 0;
    second = 0;
}

Clock::Clock(int hour, int minute, int second) {
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

void Clock::setHour(int hour) {
    this->hour = hour;
}

void Clock::setMinute(int minute) {
    this->minute = minute;
}

void Clock::setSecond(int second) {
    this->second = second;
}

int Clock::getHour() {
    return hour;
}

int Clock::getMinute() {
    return minute;
}

int Clock::getSecond() {
    return second;
}

void Clock::setDisplay(Adafruit_SSD1306* display) {
    this->display = display;
}

void Clock::render() {
    if (!display) return;
    
    display->clearDisplay();
    display->setTextSize(2);
    display->setTextColor(SSD1306_WHITE);
    display->setCursor(0,0);
    
    // 格式化时间字符串
    char timeStr[9];
    sprintf(timeStr, "%02d:%02d:%02d", hour, minute, second);
    display->println(timeStr);
    
    display->display();
}

    
