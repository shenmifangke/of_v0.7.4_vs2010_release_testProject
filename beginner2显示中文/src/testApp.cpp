#include "testApp.h"
//--------------------------------------------------------------
void testApp::setup(){	 
	ofBackground(54, 54, 54, 255);
	Text=new wstring[1];
	Text[0]=L"���ڳ��������ˣ����򵥰�";
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	word.Text=Text[0];
	word.init(300,300,12);//��ʼ�����֣�����λ�ú�����
	//word.flag=140; //��ȥ����̬Ч�����ͻָ�����ע�͡�
	word.drawText();
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
