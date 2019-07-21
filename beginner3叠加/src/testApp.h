#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		
		
    
        ofBlendMode blendMode;
        ofImage rainbow;
        float           alpha;
		float 			counter;
		ofTrueTypeFont 	vagRounded;
		//ofTrueTypeFont 	vagRounded2;
		char eventString[255];
		char backstr[255];
		char equationstr[255];
		ofImage cat;
		ofImage snow;
		bool mode1;
		bool mode2;
		int up,left,equat,disp;
};

