#include "ofApp.h"

#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Base64Encoder.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/Net/StringPartSource.h"
#include "Poco/StreamCopier.h"
#include "Poco/Buffer.h"

#include "watcher.h"
#include "emotionFinder.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = 640;  // try to grab at this size.
    camHeight = 480;
    
    shutter = false;
    
    serverURL = "www.emoticam.net";
    serverPath = "/receiver/";
    
    //we can now get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    for(int i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    
    ofSetVerticalSync(true);
    
    listener = new ofGlobalListener;
    listener->init();
    
    found = "";
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofBackground(100, 100, 100);
    
    if(shutter && vidGrabber.isInitialized()){
        vidGrabber.update();
        if(vidGrabber.isFrameNew()){
            ofPixels & pixels = vidGrabber.getPixels();
            image.setFromPixels(vidGrabber.getPixels());
            //image.saveImage(ofToString("test.jpg"));
            
            
            // Create a client session and request object for http://example.com/upload.php
            Poco::Net::HTTPClientSession s(serverURL,80);
            Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_POST, serverPath);
            
            // Create a new HTMLForm to submit to and add some basic string data
            Poco::Net::HTMLForm form;
            //form.add("token", "APP_TOKEN");
            //form.add("username", "USERNAME");
            //form.add("password", "PASSWORD_HASH");
            
            // Take a screenshot of the current openFrameworks app
            ofImage screenImg;
            screenImg.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
            screenImg.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
            ofBuffer buffer;
            ofSaveImage(image.getPixelsRef(), buffer, OF_IMAGE_FORMAT_JPEG, OF_IMAGE_QUALITY_BEST);
            
            // Convert the binary image data to string using base64 encoding
            stringstream ss;
            Poco::Base64Encoder b64enc(ss);
            b64enc << buffer;
            
            // Add the encodeded image data to the form
            form.add("face", ss.str());
            form.add("emotion", found);
            
            // Fill out the request object and write to output stream
            form.prepareSubmit(request);
            ostream& send = s.sendRequest(request);
            form.write(send);
            
            // Get and print out the response from the server
            Poco::Net::HTTPResponse response;
            istream& res = s.receiveResponse(response);
            ostringstream stream;
            Poco::StreamCopier::copyStream(res, stream);
            cout << stream.str() << endl;
            
            shutter = false;
            found = "";
            vidGrabber.close();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'g' || key == 'G'){
        if(!shutter){
            vidGrabber.initGrabber(camWidth, camHeight);
            shutter = true;
        }
    }
}

void ofApp::receiveChar(int x){
    ofLog(OF_LOG_NOTICE, "the number is " + ofToString(x));
    
}

void testReceiver(float & volume){
    ofLog(OF_LOG_NOTICE, "received a float");
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    if(!shutter){
        found = msg.message;
        vidGrabber.initGrabber(camWidth, camHeight);
        shutter = true;
    }
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
