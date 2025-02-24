#ifndef MUSIC_H
#define MUSIC_H

#include "Renderable.h"
#include <Adafruit_SSD1306.h>

class Music : public Renderable {
private:
    Adafruit_SSD1306* display;
    const char* currentTrack;
    bool isPlaying;
    
public:
    Music();
    void setDisplay(Adafruit_SSD1306* display);
    void play();
    void pause();
    void nextTrack();
    void prevTrack();
    virtual void render() override;
};

#endif 