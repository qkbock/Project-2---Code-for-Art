#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //set settings
    ofSetFrameRate(400);
    ofSetCircleResolution(100);
    ofBackground(127);
    
    //set up circles
    for(int i = 0; i < NUMBER_OF_CIRCLES; i++){
        circles[i].initiate();
    }
    //set up blue
    for(int i = 0; i < NUMBER_OF_BLUE; i++){
        blues[i].initiate();
    }
    //set up red
    for(int i = 0; i < NUMBER_OF_RED; i++){
        reds[i].initiate();
    }
    //set up green
    for(int i = 0; i < NUMBER_OF_GREEN; i++){
        greens[i].initiate();
    }
}


//--------------------------------------------------------------
void testApp::update(){
    //move blue
    for(int i = 0; i < NUMBER_OF_BLUE; i++){
        blues[i].move();
    }
    for(int i = 0; i < NUMBER_OF_RED; i++){
        reds[i].move();
    }
    for(int i = 0; i < NUMBER_OF_GREEN; i++){
        greens[i].move();
    }
    
    //check for blue intersections with circles and do transactions
    for(int i = 0; i<NUMBER_OF_BLUE; i++){
        for(int j = 0; j<NUMBER_OF_CIRCLES; j++){
            float distance = ofDist(circles[j].position.x, circles[j].position.y, blues[i].position.x, blues[i].position.y);
            
            if(distance < circles[j].size && blues[i].lastTransfer != j){
                if(blues[i].full == true && circles[j].color.b < 255){
                    circles[j].addBlue();
                    blues[i].full = false;
                    blues[i].lastTransfer = j;
                } else if(blues[i].full == false && circles[j].color.b > 0){
                    circles[j].removeBlue();
                    blues[i].full = true;
                    blues[i].lastTransfer = j;
                }
            }
        }
    }
    
    for(int i = 0; i<NUMBER_OF_RED; i++){
        for(int j = 0; j<NUMBER_OF_CIRCLES; j++){
            float distance = ofDist(circles[j].position.x, circles[j].position.y, reds[i].position.x, reds[i].position.y);
            
            if(distance < circles[j].size && reds[i].lastTransfer != j){
                if(reds[i].full == true && circles[j].color.r < 255){
                    circles[j].addRed();
                    reds[i].full = false;
                    reds[i].lastTransfer = j;
                } else if(reds[i].full == false && circles[j].color.r > 0){
                    circles[j].removeRed();
                    reds[i].full = true;
                    reds[i].lastTransfer = j;
                }
            }
        }
    }
    
    for(int i = 0; i<NUMBER_OF_GREEN; i++){
        for(int j = 0; j<NUMBER_OF_CIRCLES; j++){
            float distance = ofDist(circles[j].position.x, circles[j].position.y, greens[i].position.x, greens[i].position.y);
            
            if(distance < circles[j].size && greens[i].lastTransfer != j){
                if(greens[i].full == true && circles[j].color.g < 255){
                    circles[j].addGreen();
                    greens[i].full = false;
                    greens[i].lastTransfer = j;
                } else if(greens[i].full == false && circles[j].color.g > 0){
                    circles[j].removeGreen();
                    greens[i].full = true;
                    greens[i].lastTransfer = j;
                }
            }
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    //draw circles
    for(int i = 0; i < NUMBER_OF_CIRCLES; i++){
        circles[i].display(showMsg);
    }


    //draw blue
    if(showBlue){
        for(int i = 0; i < NUMBER_OF_BLUE; i++){
            blues[i].display();
        }
    }
    
    if(showRed){
        for(int i = 0; i < NUMBER_OF_RED; i++){
            reds[i].display();
        }
    }
    if(showGreen){
        for(int i = 0; i < NUMBER_OF_GREEN; i++){
            greens[i].display();
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    //toggle red
    if(key == 'r'){
        showRed = !showRed;
    }
    //toggle green
    if(key == 'g'){
        showGreen = !showGreen;
    }
    //toggle blue
    if(key == 'b'){
        showBlue = !showBlue;
    }
    //toggle msg
    if(key == 'm'){
        showMsg = !showMsg;
    }
    if(key == 'q'){
        float xloc = 50;
        float yloc = 50;
        for(int j = 0; j < NUMBER_OF_CIRCLES; j++){
            circles[j].makeGrid(xloc, yloc);
            xloc += 100;
            if(xloc > 800){
                xloc = 50;
                yloc += 100;
            }
        }
    }
    
    //reset circles
    if(key == 'c'){
        for(int i = 0; i < NUMBER_OF_CIRCLES; i++){
            circles[i].initiate();
        }
    }
    
    if(key == 'W'){
        ofBackground(255);
    }
    if(key == 'G'){
        ofBackground(127);
    }
    if(key == 'B'){
        ofBackground(0);
    }
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    //move around one blue one as a test
    blues[0].position.x = x;
    blues[0].position.y = y;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}