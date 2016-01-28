#include "watcher.h"

#include "ofMain.h"
#include "ofApp.h"
#include "emotionFinder.h"

#import <Cocoa/Cocoa.h>

#ifdef TARGET_OSX
#include <Cocoa/Cocoa.h>
#endif

void ofGlobalListener::init(){
    
    emotionFinder *ef = new emotionFinder;
    ef->init();
    
    [NSEvent addGlobalMonitorForEventsMatchingMask:NSKeyDownMask handler:^(NSEvent *event) {
        NSString *str = [event characters];
        char kc = [str characterAtIndex:0];
        ef->processInput(kc);
        //int kc = [event characters];
        //ofLog(OF_LOG_NOTICE, [event characters]);
       // ef->processInput(kc);
    }];
    
     [NSEvent addGlobalMonitorForEventsMatchingMask:NSLeftMouseUp handler:^(NSEvent *event) {
        ef->checkInput();
     }];
     
     [NSEvent addGlobalMonitorForEventsMatchingMask:NSRightMouseUp handler:^(NSEvent *event) {
        ef->checkInput();
     }];
     
     [NSEvent addGlobalMonitorForEventsMatchingMask:NSOtherMouseUp handler:^(NSEvent *event) {
        ef->checkInput();
     }];
     
     [NSEvent addGlobalMonitorForEventsMatchingMask:NSLeftMouseDragged handler:^(NSEvent *event) {
        ef->checkInput();
     }];
     
     [NSEvent addGlobalMonitorForEventsMatchingMask:NSRightMouseDragged handler:^(NSEvent *event) {
        ef->checkInput();
     }];
     
     [NSEvent addGlobalMonitorForEventsMatchingMask:NSOtherMouseDragged handler:^(NSEvent *event) {
        ef->checkInput();
     }];
    
}