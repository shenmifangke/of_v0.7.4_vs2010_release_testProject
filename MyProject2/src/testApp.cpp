#include "testApp.h"
//https://github.com/rezaali/ofxUI
void testApp::setup()
{	//环境设置
	ofSetVerticalSync(true);//垂直刷新 开着会降低效率 但是画质更好 
	ofEnableSmoothing();
	//ofSetWindowShape(1040,480);//这个大小设置优先
	//ofBackground(0,0,0);
	ofSetBackgroundAuto(false);//画面停止刷新 对UI无效
	//ofEnableAlphaBlending();



	drawPadding = false;//只是一个控制变量
	canDraw = false;



	//基础设置
	gui = new ofxUICanvas(0,0,400,600);//不加参数 就是自适应 加了就是那个大小 超过的会被裁剪
	red = 0; blue = 0; green = 0;//背景颜色变量等等
	ofBackground(red, green, blue);

	gui->addLabel("MyProject2", OFX_UI_FONT_LARGE);//大标题
	gui->addFPSSlider("FPS SLIDER",200, 50, 100);//帧率检测
	
	gui->addSpacer();//分割线 可以根据参数调方向
	gui->addLabel("BUTTONS", OFX_UI_FONT_MEDIUM);//中标题
	gui->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);//改成往右排
	gui->addButton("B1", false, 44, 44);
	gui->addButton("B2", false);
	gui->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN); //改成往下排
	gui->addWidgetDown(new ofxUISlider(304,16,0.0,255.0,100.0,"BACKGROUND VALUE"));
	gui->addSlider("slider",100,200,150,200,180); 
	gui->addWidgetDown(new ofxUIToggle(32, 32, false, "FULLSCREEN"));//切换按钮



	ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);//众多项目只需要加一个侦听就可以了 用名字来区分

	//临时画板初始化
	this->tempCanvas.allocate(ofGetWindowWidth(),ofGetWindowHeight(),GL_RGBA);

	//自制取色器

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
		//ofEnableBlendMode(OF_BLENDMODE_ALPHA);//这句是什么
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

	////画在中间一个透明的圆
	//ofPushStyle(); 
	//ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	//ofSetColor(255,0,0,120);
	//ofCircle(ofPoint(ofGetWindowWidth()/2,ofGetWindowHeight()/2),50);
	//ofPopStyle(); 

	tempCanvas.draw(0,0);//放在draw才显示
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
	//else if(kind == OFX_UI_WIDGET_TOGGLE)//对一类UI整体的操作
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
	//gui->saveSettings("GUI/guiSettings.xml");//关闭时保存UI信息
	delete gui; 
}
//--------------------------------------------------------------
//快捷键
void testApp::keyPressed(int key)
{
	switch (key) 
	{
	case 'p':
		{
			drawPadding = !drawPadding; //是否画UI边界
			gui->setDrawWidgetPadding(drawPadding);          
		}
		break;

	case 'h':
		{
			gui->toggleVisible(); //切换可见
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
	if(button == 0)//左键
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