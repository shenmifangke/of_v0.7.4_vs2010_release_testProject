#include "baozi.h"


baozi::baozi(void)
{
}


baozi::~baozi(void)
{

}
void baozi::setup()
{
	ofTrueTypeFont::setGlobalDpi(72);

	verdana14.loadFont("verdana.ttf", 14, true, true);
	verdana14.setLineHeight(18.0f);
	verdana14.setLetterSpacing(1.037);

	verdana30.loadFont("verdana.ttf", 30, true, true);
	verdana30.setLineHeight(34.0f);
	verdana30.setLetterSpacing(1.035);

	verdana14A.loadFont("frabk.ttf", 14, false);
	verdana14A.setLineHeight(18.0f);
	verdana14A.setLetterSpacing(1.037);
	bFirst  = true;
	typeStr = "ABCD";
}
void baozi::display()
{

}
void baozi::text_conversion()
{
	ofPushMatrix();
	string rotZ = "R";
	ofRectangle bounds = verdana30.getStringBoundingBox(rotZ, 0, 0);
	ofTranslate(110 + bounds.width/2, 300 + bounds.height / 2, 0);
	ofRotateZ(ofGetElapsedTimef() * -30.0);
	glColor4f(1,0,1,0.5);
	verdana30.drawString(rotZ, -bounds.width/2, bounds.height/2 );
	ofPopMatrix();
}
