#include "testApp.h"
//https://github.com/rezaali/ofxUI
void testApp::setup()
{	//��������
	ofSetVerticalSync(true);//��ֱˢ�� ���Żή��Ч�� ���ǻ��ʸ��� 
	ofEnableSmoothing();
	//ofSetWindowShape(1040,480);//�����С��������
	//ofBackground(0,0,0);
	ofSetBackgroundAuto(false);//����ֹͣˢ�� ��UI��Ч
	//ofEnableAlphaBlending();



	drawPadding = false;//ֻ��һ�����Ʊ���
	canDraw = false;



	//��������
	gui = new ofxUICanvas(0,0,400,600);//���Ӳ��� ��������Ӧ ���˾����Ǹ���С �����Ļᱻ�ü�
	red = 0; blue = 0; green = 0;//������ɫ�����ȵ�
	ofBackground(red, green, blue);

	gui->addLabel("MyProject2", OFX_UI_FONT_LARGE);//�����
	gui->addFPSSlider("FPS SLIDER",200, 50, 100);//֡�ʼ��
	
	gui->addSpacer();//�ָ��� ���Ը��ݲ���������
	gui->addLabel("BUTTONS", OFX_UI_FONT_MEDIUM);//�б���
	gui->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);//�ĳ�������
	gui->addButton("B1", false, 44, 44);
	gui->addButton("B2", false);
	gui->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN); //�ĳ�������
	gui->addWidgetDown(new ofxUISlider(304,16,0.0,255.0,100.0,"BACKGROUND VALUE"));
	gui->addSlider("slider",100,200,150,200,180); 
	gui->addWidgetDown(new ofxUIToggle(32, 32, false, "FULLSCREEN"));//�л���ť



	ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);//�ڶ���Ŀֻ��Ҫ��һ�������Ϳ����� ������������

	//��ʱ�����ʼ��
	this->tempCanvas.allocate(ofGetWindowWidth(),ofGetWindowHeight(),GL_RGBA);

	//����ȡɫ��

	/*gui->addSpacer();
	gui->addLabel("TOGGLES", OFX_UI_FONT_MEDIUM);
	gui->addToggle("T1", false, 44, 44);
	gui->addToggle("T2", false);
	gui->addSpacer();

	vector<string> hnames; hnames.push_back("OPEN"); hnames.push_back("FRAME"); hnames.push_back("WORKS");
	gui->addLabel("HORIZONTAL RADIO", OFX_UI_FONT_MEDIUM); 	
	gui->addRadio("HR", hnames, OFX_UI_ORIENTATION_HORIZONTAL);

	gui->addSpacer();

	vector<string> vnames; vnames.push_back("ROCKS"); vnames.push_back("MY"); vnames.push_back("SOCKS");
	gui->addLabel("VERTICAL RADIO", OFX_UI_FONT_MEDIUM);
	ofxUIRadio *radio = gui->addRadio("VR", vnames, OFX_UI_ORIENTATION_VERTICAL);
	radio->activateToggle("SOCKS");

	gui->addSpacer(); 

	gui->addLabelButton("LABEL BTN", false);
	gui->addLabelButton("JUSTIFIED LEFT BTN", false, true);

	gui->addLabelToggle("LABEL TGL", false);
	gui->addLabelToggle("JUSTIFIED LEFT TGL", false, true);

	gui->addSpacer(); 
	gui->addToggleMatrix("3X3 MATRIX", 3, 3); 
	gui->addToggleMatrix("DISABLE MULTIPLE", 3, 3);

	ofxUIToggleMatrix* mtx = (ofxUIToggleMatrix *) gui->getWidget("DISABLE MULTIPLE"); 
	mtx->setAllowMultiple(false); 
	gui->addToggleMatrix("CUSTOM SIZE", 1,6);

	gui->addSpacer(); 
	gui->addLabel("IMAGE BUTTON/TOGGLE", OFX_UI_FONT_MEDIUM); 
	gui->addImageButton("IMAGE BUTTON", "GUI/pause.png", false, 44, 44);
	gui->addImageToggle("IMAGE TOGGLE", "GUI/play.png", false, 44, 44);
	gui->autoSizeToFitWidgets();    
	ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);	



	gui->setColorBack(ofColor(255,100));
	gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(255,100));*/
}

//--------------------------------------------------------------
void testApp::update()
{
	if(canDraw){
	tempCanvas.begin();
	ofPushStyle();
	{
		ofSetColor(ofColor(255,255,255));
		//ofEnableBlendMode(OF_BLENDMODE_ALPHA);//�����ʲô
		ofCircle(ofPoint(mouseX,mouseY),20);
	}
	ofPopStyle();
	tempCanvas.end();
	}
	
}

//--------------------------------------------------------------
void testApp::draw()
{
	ofBackground(red, green, blue, 255); 

	////�����м�һ��͸����Բ
	//ofPushStyle(); 
	//ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	//ofSetColor(255,0,0,120);
	//ofCircle(ofPoint(ofGetWindowWidth()/2,ofGetWindowHeight()/2),50);
	//ofPopStyle(); 

	tempCanvas.draw(0,0);//����draw����ʾ
}
//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName(); 
	int kind = e.widget->getKind(); 

	if(kind == OFX_UI_WIDGET_BUTTON)
	{
		ofxUIButton *button = (ofxUIButton *) e.widget; 
		cout << name << "\t value: " << button->getValue() << endl;         
	}
	//else if(kind == OFX_UI_WIDGET_TOGGLE)//��һ��UI����Ĳ���
	//{
	//	ofxUIToggle *toggle = (ofxUIToggle *) e.widget; 
	//	cout << name << "\t value: " << toggle->getValue() << endl;             
	//}
	else if(kind == OFX_UI_WIDGET_IMAGEBUTTON)
	{
		ofxUIImageButton *button = (ofxUIImageButton *) e.widget; 
		cout << name << "\t value: " << button->getValue() << endl;                 
	}
	else if(kind == OFX_UI_WIDGET_IMAGETOGGLE)
	{
		ofxUIImageToggle *toggle = (ofxUIImageToggle *) e.widget; 
		cout << name << "\t value: " << toggle->getValue() << endl;                 
	}
	else if(kind == OFX_UI_WIDGET_LABELBUTTON)
	{
		ofxUILabelButton *button = (ofxUILabelButton *) e.widget; 
		cout << name << "\t value: " << button->getValue() << endl;                 
	}
	else if(kind == OFX_UI_WIDGET_LABELTOGGLE)
	{
		ofxUILabelToggle *toggle = (ofxUILabelToggle *) e.widget; 
		cout << name << "\t value: " << toggle->getValue() << endl;                 
	}
	else if(name == "B1")
	{
		ofxUIButton *button = (ofxUIButton *) e.widget; 
		cout << "value: " << button->getValue() << endl; 
	}
	else if(name == "B2")
	{
		ofxUIButton *button = (ofxUIButton *) e.widget; 
		cout << "value: " << button->getValue() << endl;         
	}
	else if(name == "T1")
	{
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget; 
		cout << "value: " << toggle->getValue() << endl;     
	}
	else if(name == "T2")
	{
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget; 
		cout << "value: " << toggle->getValue() << endl;     
	}
	else if(e.widget->getName() == "FULLSCREEN")
	{
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		ofSetFullscreen(toggle->getValue()); 
	} 
}
//--------------------------------------------------------------
void testApp::exit()
{
	//gui->saveSettings("GUI/guiSettings.xml");//�ر�ʱ����UI��Ϣ
	delete gui; 
}
//--------------------------------------------------------------
//��ݼ�
void testApp::keyPressed(int key)
{
	switch (key) 
	{
	case 'p':
		{
			drawPadding = !drawPadding; //�Ƿ�UI�߽�
			gui->setDrawWidgetPadding(drawPadding);          
		}
		break;

	case 'h':
		{
			gui->toggleVisible(); //�л��ɼ�
		}
		break; 
	case 'f':
		{
			ofToggleFullscreen(); 
			break;
		}
	default:
		break;
	}
}
//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{ 

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
	if(button == 0)//���
	{canDraw = true;}
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
	if(button == 0){
	canDraw = false;}
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{


}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}