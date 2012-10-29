//
//  Green.h
//  colorTrading
//
//  Created by Quincy Bock on 10/21/12.
//
//

#pragma once
#include "ofMain.h"
#include "testApp.h"


class Green {
public:
    
    void initiate(){
        full = true;
        position.x = ofRandomWidth();
        position.y = ofRandomHeight();
        speed = 1;
        angle = ofRandom(0, 2*PI);
        size = 2;
        lastTransfer = -1;
    }
    
    void move(){
        rotation = ofRandom(-PI/8, PI/8);
        angle += rotation;
        velocity.x = cos(angle)*speed;
        velocity.y = sin(angle)*speed;
        position.x += velocity.x;
        position.y += velocity.y;
        edges();
    }
    
    void display(){
        if(full == true){
            ofSetColor(0, 255, 0);
        }
        else{
            ofSetColor(255, 0, 255);
        }
        ofCircle(position, size);
    }
    
    void edges(){
        if(position.x < 0){
            position.x = ofGetWidth();
        }
        if(position.x > ofGetWidth()){
            position.x = 0;
        }
        if(position.y < 0){
            position.y = ofGetHeight();
        }
        if(position.y > ofGetHeight()){
            position.y = 0;
        }
    }
    
    bool full;
    ofPoint position;
    ofPoint positionLast;
    ofPoint velocity;
    float speed;
    float angle;
    float rotation;
    float size;
    int lastTransfer;
    
};
