#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"
//下面是去掉GLUT的控制台窗口方法
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
//========================================================================
int main( ){

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1000,500, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new testApp());

}
