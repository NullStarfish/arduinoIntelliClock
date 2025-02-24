#ifndef COMPONENT_H
#define COMPONENT_H

#include <Adafruit_SSD1306.h>

class Component {
public:
    virtual void render(Adafruit_SSD1306* display) = 0;
    void setPosition(int x, int y);
    void setSize(int width, int height);
    
protected:
    int x, y;
    int width, height;
};

#endif 