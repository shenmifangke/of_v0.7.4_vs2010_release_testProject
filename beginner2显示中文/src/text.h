#pragma once
#pragma comment(lib, "ftgl_static.lib")//���ĺ���
#include "ftgl/ftgl.h"
#include "ofMain.h"
class text
{
public:
	text();
	~text(void);


    wstring Text;
	wstring *myText;
	FTFont *myFont;//�Զ�������

	ofPoint center;   //�����Բ����ʾ��Բ��
    ofPoint *points;  //���������ֵ�λ��
	ofPoint *endPoints;//�����Բ����ʾ��ԲȦ�յ�
	float* degree;//�����˶������е���ת��
	float* degree2;//�����˶����ع����е���ת��
	int flag;
	int circleNum ; 
	void drawCharacter(float x,float y,wstring str,float degrees);//��������

	void drawText(void);
	void circle(int num);//�����AȦ���ֶ����F��߅�����AȦ���ֳ�num��
	void init(int pos_centerX,int pos_centerY,int text_num);
	float dx;
	float dy;
	

};
