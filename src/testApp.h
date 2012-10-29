#pragma once

#include "ofMain.h"
#include "Red.h"
#include "Green.h"
#include "Blue.h"
#include "Circle.h"

#define NUMBER_OF_CIRCLES 64
#define NUMBER_OF_BLUE 25
#define NUMBER_OF_RED 25
#define NUMBER_OF_GREEN 25
#define GRID_EDGE 8

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    int counter;
    Circle circles[NUMBER_OF_CIRCLES];
    Blue blues[NUMBER_OF_BLUE];
    Red reds[NUMBER_OF_RED];
    Green greens[NUMBER_OF_GREEN];
    bool showRed;
    bool showGreen;
    bool showBlue;
    bool showMsg;
		
};
