#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	fbo.allocate(ofGetWidth(), ofGetHeight());

	clearBack = false;

	style_factor = 0.05;
}

//--------------------------------------------------------------
void testApp::update(){
	ofBackground(100, 100, 70);
}

//--------------------------------------------------------------
void testApp::draw(){


	fbo.begin();
	
	ofEnableAlphaBlending();
	//pdraw.draw_sampler();
	ofPushStyle();			// 建议颜色设置放这里
	ofSetColor(0, 0, 0);
	ofFill();
	// 100次，控制绘制速度
	for ( int i = 0; i < 100; i++ )	
	{
		pdraw.update();
		pdraw.render();
	}
	ofPopStyle();
	if (clearBack)  //一次清屏
	{	
		ofPushStyle();
		ofSetColor(100, 100, 70);
		ofRect(0, 0, ofGetWidth(), ofGetHeight());
		ofPopStyle();
		clearBack = false;
	}
	// 背景色
	
	fbo.end();
	fbo.draw(0,0);
	ofDrawBitmapString("size:"+ofToString(pdraw.size_draw_factor), 10, 10);
	ofDrawBitmapString("factor:"+ofToString(pdraw.size_lerp_factor, 3), 10, 20);
	ofDrawBitmapString("pres 'b' clear screen, up & down arrow change size", 10, 30);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if ( key == 'c' )
	{
		pdraw.release_sampler();
	}
	if ( key == 'b' )
	{
		clearBack = true;
	}


	if ( key == OF_KEY_UP )
	{
		pdraw.size_draw_factor += 10;
	}
	if ( key == OF_KEY_DOWN )
	{
		pdraw.size_draw_factor -= 10;
	}

	if ( key == OF_KEY_LEFT )
	{
		pdraw.size_lerp_factor -= 0.01;
	}

	if ( key == OF_KEY_RIGHT )
	{
		pdraw.size_lerp_factor += 0.01;
	}

	switch (key) 
	{
	case 'f':
		{
			ofToggleFullscreen(); 
			break;
		}
	default:
		break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	pdraw.get_sampler_per_time(x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	pdraw.get_sampler_per_time(x, y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	//pdraw.release_sampler();//想去除连笔功能恢复这句。
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