#include "testApp.h"
//--------------------------------------------------------------
GLuint foreground[]={GL_ZERO,GL_ONE,GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR,GL_DST_COLOR,GL_ONE_MINUS_DST_COLOR,GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA,GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA,GL_SRC_ALPHA_SATURATE,GL_CONSTANT_COLOR,GL_ONE_MINUS_CONSTANT_COLOR,GL_CONSTANT_ALPHA,GL_ONE_MINUS_CONSTANT_ALPHA};
GLuint background[]={GL_ZERO,GL_ONE,GL_SRC_COLOR,GL_ONE_MINUS_SRC_COLOR,GL_DST_COLOR,GL_ONE_MINUS_DST_COLOR,GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA,GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA,GL_SRC_ALPHA_SATURATE,GL_CONSTANT_COLOR,GL_ONE_MINUS_CONSTANT_COLOR,GL_CONSTANT_ALPHA,GL_ONE_MINUS_CONSTANT_ALPHA};
GLuint equation[]={GL_FUNC_ADD,GL_FUNC_SUBTRACT,GL_FUNC_REVERSE_SUBTRACT};
string wordfore[]={"ZERO","ONE","SRC_COLOR","ONE_MINUS_SRC_COLOR","DST_COLOR","ONE_MINUS_DST_COLOR","SRC_ALPHA","ONE_MINUS_SRC_ALPHA","DST_ALPHA","ONE_MINUS_DST_ALPHA","SRC_ALPHA_SATURATE","CONSTANT_COLOR","ONE_MINUS_CONSTANT_COLOR","CONSTANT_ALPHA","ONE_MINUS_CONSTANT_ALPHA"};
string wordback[]={"ZERO","ONE","SRC_COLOR","ONE_MINUS_SRC_COLOR","DST_COLOR","ONE_MINUS_DST_COLOR","SRC_ALPHA","ONE_MINUS_SRC_ALPHA","DST_ALPHA","ONE_MINUS_DST_ALPHA","SRC_ALPHA_SATURATE","CONSTANT_COLOR","ONE_MINUS_CONSTANT_COLOR","CONSTANT_ALPHA","ONE_MINUS_CONSTANT_ALPHA"};
string wordequation[]={"FUNC_ADD","FUNC_SUBTRACT","FUNC_REVERSE_SUBTRACT"};
void testApp::setup(){	 
    sprintf(eventString, "Alpha"); 
	sprintf(backstr, "Alpha"); 
	sprintf(equationstr, "Alpha"); 
	vagRounded.loadFont("vag.ttf", 32);
	ofBackground(50,50,50);	
	left=up=equat=0;
	snow.loadImage("images/forest2.png");
	cat.loadImage("images/cat16.png");
}


//--------------------------------------------------------------
void testApp::update(){

}
//--------------------------------------------------------------
void testApp::draw(){
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//清缓冲区
		//glBlendFuncSeparate(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA,GL_ZERO,GL_ONE);//如果混合因子出现问题，比如混合后不该出现的黑色区域出现了，那是因为alpha通道的内容美誉哦单独拿出来混合，所以要用这句。
		glBlendFunc(foreground[left],background[up]);
		glBlendEquation(equation[equat]);
		snow.draw(400, 300);   //绘制背景
		glEnable(GL_BLEND);   //开启混合模式
 		cat.draw(400, 300);   //绘制源图
		glDisable (GL_BLEND); //关闭混合模式
		glFlush();
		ofPushStyle();
		ofSetHexColor(0xffffff);
		vagRounded.drawString("fore:",10,50);
		vagRounded.drawString(eventString,10,98);
		ofSetColor(255,122,220);
		vagRounded.drawString(eventString, 12,100);
		ofSetHexColor(0xffffff);
		vagRounded.drawString("back:",10,145);
		vagRounded.drawString(backstr,10,198);
		ofSetColor(255,122,220);
		vagRounded.drawString(backstr, 12,200);
		ofSetHexColor(0xffffff);
		vagRounded.drawString(equationstr,10,298);
		ofSetColor(255,122,220);
		vagRounded.drawString(equationstr, 12,300);
		ofPopStyle();
}
//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 

    switch (key) {
        case OF_KEY_RIGHT:	
			left++;
			if(left==15)
			{
				left=0;
			}
            sprintf(eventString, wordfore[left].c_str()); 
            break;
        case OF_KEY_UP:
			up++;
			if(up==15)
			{
				up=0;
			}
           sprintf(backstr, wordback[up].c_str());
            break;
        case OF_KEY_LEFT:
			left--;
			if(left<0)
			{
				left=14;
			}
            sprintf(eventString, wordfore[left].c_str()); 
			break;
        case OF_KEY_DOWN:
			up--;
			if(up<0)
			{
				up=14;
			}
            sprintf(backstr, wordback[up].c_str()); 
			break;
		case 'q':
			equat++;
			if(equat>2)
			{
				equat=0;
			}
			sprintf(equationstr, wordequation[equat].c_str()); 
			break;
        default:
            break;
    }
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