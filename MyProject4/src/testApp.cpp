#include "testApp.h"
//https://github.com/rezaali/ofxUI
//  [8/6/2013 user]
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
	//gui = new ofxUICanvas(200,0,400,600);

	//gui->addLabel("BUTTONS", OFX_UI_FONT_MEDIUM);//中标题
	//
	//gui->addButton("B1", false, 44, 44);
	//gui->addButton("B2", false);
	//
	//gui->addWidgetDown(new ofxUISlider(304,16,0.0,255.0,100.0,"BACKGROUND VALUE"));
	//gui->addSlider("slider",100,200,150,200,180); 
	//gui->addWidgetDown(new ofxUIToggle(32, 32, false, "FULLSCREEN"));//切换按钮


	//自制取色器
	colorPicker = new ofxUICanvas(800,0,400,600);//不加参数 就是自适应 加了就是那个大小 超过的会被裁剪
	colorPicker->addLabel("MyProject4", OFX_UI_FONT_LARGE);//大标题
	colorPicker->addFPSSlider("FPS SLIDER",200, 5, 100);//帧率检测
	colorPicker->addLabel("colorPicker");
	colorPicker->addSpacer();//分割线 可以根据参数调方向
	red = 0;
	green = 0;
	blue = 0;
	alpha = 255;
	brushScale = 20.0/100.0;//不加.0出来的是int
	cout<<brushScale*255<<endl;
	colorPicker->addSlider("red",0,255,red,200,20);
	colorPicker->addSlider("green",0,255,green,200,20);
	colorPicker->addSlider("blue",0,255,blue,200,20);
	colorPicker->addSlider("alpha",0,255,alpha,200,20);
	colorPicker->addLabel("BrushScale",OFX_UI_FONT_SMALL);
	colorPicker->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);//改成往右排
	colorPicker->addCircleSlider("BrushScale",0,100,20,100);
	colorPicker->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN); //改成往下排
	ofAddListener(colorPicker->newGUIEvent,this,&testApp::guiEvent);//众多项目只需要加一个侦听就可以了 用名字来区分
	//初始化UI颜色
	colorPicker->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(red,green,blue,alpha));
	


	//临时画板初始化
	this->tempCanvas.allocate(ofGetWindowWidth()-200,ofGetWindowHeight(),GL_RGBA);
}

//--------------------------------------------------------------
void testApp::update()
{

	
}

//--------------------------------------------------------------
void testApp::draw()
{
	//ofBackground(red, green, blue, 255);//刷新

	////画在中间一个透明的圆
	//ofPushStyle(); 
	//ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	//ofSetColor(255,0,0,120);
	//ofCircle(ofPoint(ofGetWindowWidth()/2,ofGetWindowHeight()/2),50);
	//ofPopStyle(); 
	if(canDraw){
		tempCanvas.begin();
		glClearColor(0,0,0,0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//这两句是清空画布
		ofPushStyle();
		{
			//一开始的alpha为255所以*255后很大超出了255就变为0了 所以在此纠正 其他三张颜色一开始为0所以没有限制
			if(alpha>1)alpha =1;
			ofSetColor(ofColor(red*255,green*255,blue*255,alpha*255));
			//ofEnableBlendMode(OF_BLENDMODE_ALPHA);//这句是什么
			ofCircle(ofPoint(mouseX,mouseY),brushScale*100);
			
		}
		ofPopStyle();
		tempCanvas.end();tempCanvas.draw(0,0);//放在draw才显示？
	}
}
//--------------------------------------------------------------

void testApp::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName(); 
	int kind = e.widget->getKind(); 
	//switch条件必须是标量类型 不支持string
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
	}else if(e.widget->getName() == "FULLSCREEN")
	{
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		ofSetFullscreen(toggle->getValue()); 
	}else if(name == "red")
	{ofxUISlider *slider = (ofxUISlider *) e.widget;
	red = slider->getValue();
	}else if(name == "blue")
	{ofxUISlider *slider = (ofxUISlider *) e.widget;
	blue = slider->getValue();
	}else if(name == "green")
	{ofxUISlider *slider = (ofxUISlider *) e.widget;
	green = slider->getValue();
	}else if(name == "alpha")
	{ofxUISlider *slider = (ofxUISlider *) e.widget;
	alpha = slider->getValue();
	}else if(name == "BrushScale")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		brushScale = slider->getValue();
	}
	//一开始的alpha为255所以*255后很大超出了255就变为0了 所以在此纠正 其他三张颜色一开始为0所以没有限制
	if(alpha>1)alpha =1;
	//设置颜色
	colorPicker->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(red*255,green*255,blue*255,alpha*255));
}
//--------------------------------------------------------------
void testApp::exit()
{
	//gui->saveSettings("GUI/guiSettings.xml");//关闭时保存UI信息
	//delete gui;
	delete colorPicker;
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
			colorPicker->setDrawWidgetPadding(drawPadding);          
		}
		break;

	case 'h':
		{
			colorPicker->toggleVisible(); //切换可见
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