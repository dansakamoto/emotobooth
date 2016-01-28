//
//  emotionFinder.cpp
//  emotobooth
//
//  Created by Dan Sakamoto on 1/27/16.
//
//

#include "ofMain.h"

#include "emotionFinder.h"

void emotionFinder::init(){
    stringBuffer = "";
    maxLength = 500;
    potential = true;
    
    match = "";
    
}

void emotionFinder::processInput(char c){
    
    if(c == 32 || c == 10 || c == 13){
        this->checkInput();
    } else {
        stringBuffer += c;
    }
}

void emotionFinder::checkInput(){
    
    if(stringBuffer == ":)"
       || stringBuffer == ":("
       || stringBuffer == ":D"
       || stringBuffer == ":-)"
       || stringBuffer == ":-D"
       || stringBuffer == ":P"
       || stringBuffer == ":-P"
       || stringBuffer == ":p"
       || stringBuffer == ":-p"
       || stringBuffer == "(:"
       || stringBuffer == "(-:"
       || stringBuffer == "):"
       || stringBuffer == ")-:"
       || stringBuffer == "D:"
       || stringBuffer == "D-:"
       || stringBuffer == "D8"
       || stringBuffer == "D-8"
       || stringBuffer == "8D"
       || stringBuffer == "8-D"
       || stringBuffer == ":o"
       || stringBuffer == ":-o"
       || stringBuffer == ":-|"
       || stringBuffer == ">:)"
       || stringBuffer == ">:-)"
       || stringBuffer == ">:("
       || stringBuffer == ">:-("
       || stringBuffer == ":3"
       || stringBuffer == "lmao"
       || stringBuffer == "lol"
       || stringBuffer == "ha"
       || stringBuffer == "haha"
       ){
        takePhoto(stringBuffer);
    }
    
    stringBuffer = "";
}

void emotionFinder::takePhoto(string str){
    ofSendMessage(str);
}