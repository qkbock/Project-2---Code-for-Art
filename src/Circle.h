//
//  Circle.h
//  colorTrading
//
//  Created by Quincy Bock on 10/21/12.
//
//

#pragma once
#include "ofMain.h"

class Circle {
public:

    void initiate(){
        color.r = 127;
        color.g = 127;
        color.b = 127;
        position.x = ofRandomWidth();
        position.y = ofRandomHeight();
        size = 10;
    }
    
    void display(float i){
//        constrainColors();
        ofSetColor(color);
        ofCircle(position, size);
    
        
        ofSetColor(255);
        
        float arrayLocation = i;
        stringstream msg;
        msg << "arrayLocation = " << arrayLocation << endl  << "color.b = " << color.b << endl;
        ofDrawBitmapString(msg.str(), position);
    }
    
    void addBlue(){
        color.b += 10;
        color.clamp();
    }
    
    void removeBlue(){
        color.b -= 10;
        color.clamp();
    }
    
//    void constrainColors(){
//        if(color.r > 255){
//            color.r = 255;
//        }
//        if(color.r < 0){
//            color.r = 0;
//        }
//        if(color.g > 255){
//            color.g = 255;
//        }
//        if(color.g < 0){
//            color.g = 0;
//        }
//        if(color.b > 255){
//            color.b = 255;
//        }
//        if(color.b < 0){
//            color.b = 0;
//        }
//    }
    
    
    ofPoint position;
    ofColor color;
    float size;
};