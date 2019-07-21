#pragma once
#include "ofMain.h"
#include "text.h"
class testApp : public ofBaseApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		std::string ws2s(const std::wstring& ws);
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		
		
		bool bFirst;
		string typeStr;
		
		ofTrueTypeFont  franklinBook14;
		ofTrueTypeFont	verdana14;
		ofTrueTypeFont	verdana30;
		
		ofTrueTypeFont  franklinBook14A;
		ofTrueTypeFont	verdana14A;
		text word;
		wstring* Text;//ΩÈ…‹Œƒ◊÷
};

