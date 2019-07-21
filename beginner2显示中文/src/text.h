#pragma once
#pragma comment(lib, "ftgl_static.lib")//中文汉字
#include "ftgl/ftgl.h"
#include "ofMain.h"
class text
{
public:
	text();
	~text(void);


    wstring Text;
	wstring *myText;
	FTFont *myFont;//自定义字体

	ofPoint center;   //字体变圆形显示的圆心
    ofPoint *points;  //字体最后呈现的位置
	ofPoint *endPoints;//字体变圆形显示的圆圈终点
	float* degree;//字体运动过程中的旋转角
	float* degree2;//字体运动返回过程中的旋转角
	int flag;
	int circleNum ; 
	void drawCharacter(float x,float y,wstring str,float degrees);//绘制字体

	void drawText(void);
	void circle(int num);//畫個圓圈，字都出現在邊緣，圓圈被分成num份
	void init(int pos_centerX,int pos_centerY,int text_num);
	float dx;
	float dy;
	

};
