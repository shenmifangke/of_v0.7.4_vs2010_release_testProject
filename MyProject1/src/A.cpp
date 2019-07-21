#include "A.h"


A::A(void)
{
	ofAddListener(ofEvents().setup,this,&A::setup);
	ofAddListener(ofEvents().draw, this, &A::draw);//加了以后持续输出aaa的原始值错误
}


A::~A(void)
{
}

void A::setup(ofEventArgs& e)
{
	
	ofSetFrameRate(15);
	C = ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
	a = 100.0f;
	
}
void A::draw(ofEventArgs& even)//ofEventArgs& even
{
	
	//ofSetColor(C);
	cout<<C<<endl;
	cout << a << endl;
	ofCircle(ofPoint( ofRandom(0,ofGetWindowWidth()),ofRandom(0,ofGetWindowHeight()) ),ofRandom(0,50));
}
