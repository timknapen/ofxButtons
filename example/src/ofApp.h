#pragma once

#include "ofMain.h"
#include "ofxButtons.h"

enum {
COLOR_RED,
COLOR_GREEN,
COLOR_BLUE
};


class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ButtonManager buttons;
    
    float fps;
    float fScale;
    float fRotation;
    int colorSelect;
    bool bReset;
};
