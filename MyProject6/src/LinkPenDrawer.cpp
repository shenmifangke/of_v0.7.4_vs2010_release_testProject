#include "LinkPenDrawer.h"
#include "testApp.h"



void LinkPenDrawer::render()
{
	if ( flag_draw_start )
	{
		ofPushStyle();
		ofSetColor(255);
		//cout << red<<endl;

		
		ofSetColor(ofColor(testApp::red*255,testApp::green*255,testApp::blue*255,testApp::alpha*255));
		ofCircle(pos_of_draw.x, pos_of_draw.y, size_of_draw);
		//ofRect(pos_of_draw.x, pos_of_draw.y, size_of_draw, size_of_draw);
		//ofLine(pos_of_draw.x, pos_of_draw.y, pos_of_draw.x+3, pos_of_draw.y+size_of_draw);
		ofPopStyle();
	}
}