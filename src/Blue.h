//
//  Blue.h
//  colorTrading
//
//  Created by Quincy Bock on 10/21/12.
//
//

#pragma once
#include "ofMain.h"
#include "testApp.h"


class Blue {
public:
    
    void initiate(){
        full = true;
        position.x = ofRandomWidth();
        position.y = ofRandomHeight();
        velocity.x = ofRandom(-4, 4);
        velocity.y = ofRandom(-4, 4);
        speed = .5;
        angle = 0;
        size = 2;
        lastTransfer = -1;
    }
    
    void move(int counter){
//        angle = ofNoise(counter);
//        position.x += cos(angle)*speed;
//        position.y += sin(angle)*speed;
        position.x += velocity.x;
        position.y += velocity.y;
        edges();
    }
    

    
    void display(){
        if(full == true){
            ofSetColor(0, 0, 255);
        }
        else{
            ofSetColor(255);
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
    ofPoint velocity;
    float speed;
    float angle;
    float size;
    int lastTransfer;
    
    
    float step = (float) 1/200; // length of a step
    float skew = (float) 1/10; //randomness scaling
    float thresh = (float) 1/40; // minimum distance
    
};












class Wanderer {
    float lastx, lasty, x, y, rot, rota;
    int lastchip;
    
    Wanderer() {
        carry = false;
        x = random(1);
        y = random(1);
        lastx = x;
        lasty = y;
        rot = random(TWO_PI) - PI;
        rota = 0;
    }

    void move() {
        rot += rota * skew;
        rota += random(-PI,PI);
        rot = modConstrain(rot,-PI,PI);
        rota = modConstrain(rota,-PI,PI);
        
        x += cos(rot) * step;
        x = modConstrain(x,0,1);
        y += sin(rot) * step;
        y = modConstrain(y,0,1);
    }
    

float modConstrain(float x, float low, float high) {
    float diff = high - low;
    x = (x - low) % diff;
    if(x < 0) x += diff;
    return x + low;
}