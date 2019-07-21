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
		void guiEvent(ofxUIEventArgs &e);//取色器事件
		ofxUICanvas *colorPicker;//取色器
		unsigned int pen;
		bool drawPadding;
		float red, green, blue,alpha; //画笔颜色[0,1]
		float brushScale;//画笔大小
		ofFbo tempCanvas;//临时画布
		bool canDraw;//是否按下鼠标

		
};
