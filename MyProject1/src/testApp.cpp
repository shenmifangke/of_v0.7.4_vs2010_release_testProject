#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(15);
	ofSetBackgroundAuto(false);
	//xx.setup();

	for (int i=0;i<1;i++)
	{
		A obj;
		
		//obj.aaa = 100;
		//obj.setup();
		//obj.C = ofColor(i*20,i*30,i*40,255);
		
		Container.push_back(obj);
		
		//xx.setup();
	}
	//cout<<Container.size()<<endl;
	//cout<<Container[2].aaa<<endl;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	/*for(int i=0;i<Container.size();i++)
	{
		Container[i].draw();
	}*/
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

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