#pragma once
#include "ofMain.h"
class baozi :
	public ofBaseApp
{
public:
	baozi(void);
	~baozi(void);
	void setup();
	void display();
	void text_conversion();
	bool bFirst;
	string typeStr;
	ofTrueTypeFont	verdana14;
	ofTrueTypeFont	verdana30;
	ofTrueTypeFont	verdana14A;
};

