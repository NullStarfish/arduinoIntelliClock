#ifndef CLOCK_H
#define CLOCK_H

#include "Renderable.h"
#include <Adafruit_SSD1306.h> // 或其他OLED库

class Clock : public Renderable {
  public:
    void render();
    Clock();
    Clock(int hour, int minute, int second);
    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);
    int getHour();
    int getMinute();
    int getSecond();
    void setDisplay(Adafruit_SSD1306* display); // 新增设置显示器方法
  private:
    int hour;
    int minute;
    int second;
    Adafruit_SSD1306* display; // OLED显示对象指针
};
#endif