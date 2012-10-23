#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(100);
    ofSetCircleResolution(100);
    ofBackground(0);
    counter = 0;
    for(int i = 0; i < NUMBER_OF_CIRCLES; i++){
        circles[i].initiate();
    }
    
    for(int i = 0; i < NUMBER_OF_BLUE; i++){
        blues[i].initiate();
    }
}


//--------------------------------------------------------------
void testApp::update(){
    for(int i = 0; i < NUMBER_OF_BLUE; i++){
        blues[i].move(counter);
    }
    counter++;

    for(int i = 0; i<NUMBER_OF_BLUE; i++){
        for(int j = 0; j<NUMBER_OF_CIRCLES; j++){
            float distance = ofDist(circles[j].position.x, circles[j].position.y, blues[i].position.x, blues[i].position.y);
            
            if(distance < circles[j].size && blues[i].lastTransfer != j){
                if(blues[i].full == true && circles[j].color.b < 256){
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
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i = 0; i < NUMBER_OF_CIRCLES; i++){
        circles[i].display();
    }
    
    for(int i = 0; i < NUMBER_OF_BLUE; i++){
        blues[i].display();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    for(int i = 0; i < NUMBER_OF_CIRCLES; i++){
        circles[i].initiate();
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
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