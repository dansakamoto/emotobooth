#pragma once

#include "ofMain.h"
#include "watcher.h"
#include "emotionFinder.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void testReceiver(float & volume);
    
    void receiveChar(int x);
    
    ofVideoGrabber vidGrabber;
    ofImage image;
    ofGlobalListener *listener;
    
    ofEvent<float> onVolumeChange;
    
    //ofGlobalListener listener;
    
    int camWidth;
    int camHeight;
    
    bool shutter;
    
    string serverURL;
    string serverPath;
    string found;
    
    //string responseStr;
    //string requestStr;
    //string action_url;
    
};
