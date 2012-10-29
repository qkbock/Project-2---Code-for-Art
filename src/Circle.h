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
        size = 12.0;
        incriment = 10;
    }
    
    void makeGrid(int x, int y){
        color.r = 127;
        color.g = 127;
        color.b = 127;
        position.x = x;
        position.y = y;
        size = 8.0;
        incriment = 10;
    }
    
    void display(bool msg){
        ofSetColor(color);
        ofCircle(position, size);        
        if(msg){
            ofSetColor(255);
            stringstream msg;
            msg << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << endl;
            ofDrawBitmapString(msg.str(), position.x-53, position.y+28);
        }
    }
    
    void addBlue(){
        if( ((int)color.b + incriment) <= 255 ){
            color.b += incriment;
            color.clamp();
        }
        else{
            color.b = 255;
        }
    }
    void removeBlue(){
        if( ((int)color.b - incriment) >= 0 ){
            color.b -= incriment;
            color.clamp();
        }
        else{
            color.b = 0;
        }
    }
    
    void addRed(){
        if( ((int)color.r + incriment) <= 255 ){
            color.r += incriment;
            color.clamp();
        }
        else{
            color.r = 255;
        }
    }
    void removeRed(){
        if( ((int)color.r - incriment) >= 0 ){
            color.r -= incriment;
            color.clamp();
        }
        else{
            color.r = 0;
        }
    }
    
    void addGreen(){
        if( ((int)color.g + incriment) <= 255 ){
            color.g += incriment;
            color.clamp();
        }
        else{
            color.g = 255;
        }
    }
    void removeGreen(){
        if( ((int)color.g - incriment) >= 0 ){
            color.g -= incriment;
            color.clamp();
        }
        else{
            color.g = 0;
        }
    }
    
    
    
    float incriment;
    ofPoint position;
    ofColor color;
    float size;
};