#pragma once

#include "ofGraphics.h"
#include "ofImage.h"


class emotionFinder {
public:
    void processInput(char c);
    void checkInput();
    void init();
    void takePhoto(string str);
    
    string stringBuffer;
    string match;
    
    bool potential;
    
    int maxLength;
};