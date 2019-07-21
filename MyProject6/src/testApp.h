#pragma once
#ifndef TESTAPP_H
#define TESTAPP_H

#include "ofMain.h"
#include "ofxUI.h"
//��һ�ֻ���
#include "LinkPenDrawer.h"



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
	void guiEvent(ofxUIEventArgs &e);//ȡɫ���¼�
	ofxUICanvas *colorPicker;//ȡɫ��
	unsigned int pen;
	bool drawPadding;

	float brushScale;//���ʴ�С
	ofFbo tempCanvas;//��ʱ����
	bool canDraw;//�Ƿ������

	LinkPenDrawer pdraw;

	ofFbo tempBrush;//��ʱ����

	//3d
	ofMesh mesh;
	ofEasyCam cam;
	//shader
	ofTrueTypeFont font;
	ofShader shader;

	static float red,green,blue,alpha;

};

#endif




