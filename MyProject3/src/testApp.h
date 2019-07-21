#pragma once

#include "ofMain.h"
#include "ofxUI.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit(); 

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		//ofxUICanvas *gui;   	
		void guiEvent(ofxUIEventArgs &e);
		ofxUICanvas *colorPicker;
		//void colorPickerEvent(ofxUIEventArgs &e);//取色器事件
		bool drawPadding; 
		float red, green, blue,alpha; //[0,1]

		ofFbo tempCanvas;
		bool canDraw;

		
};
