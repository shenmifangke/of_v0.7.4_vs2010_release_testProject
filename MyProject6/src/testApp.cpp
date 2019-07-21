#include "testApp.h"
//https://github.com/rezaali/ofxUI
//  [8/6/2013 user]


float testApp::red = 1.0f;
float testApp::green = 1.0f;
float testApp::blue = 1.0f;
float testApp::alpha = 1.0f;

void testApp::setup()
{	//��������
	ofSetLogLevel(OF_LOG_VERBOSE);//������shader
	ofSetVerticalSync(true);//��ֱˢ�� ���Żή��Ч�� ���ǻ��ʸ��� 
	ofEnableSmoothing();
	//ofSetCircleResolution(50);//���ʲô��
	//ofSetWindowShape(1040,480);//�����С��������
	//ofBackground(0,0,0);
	//ofSetBackgroundAuto(false);//����ֹͣˢ�� ��UI��Ч ������������� ���λ������֮�� 
	ofEnableAlphaBlending();
	ofSetBackgroundAuto(false);

	drawPadding =false;//����UI���߿�
	canDraw = false;


	//��������
	//gui = new ofxUICanvas(200,0,400,600);

	//gui->addLabel("BUTTONS", OFX_UI_FONT_MEDIUM);//�б���
	//
	//gui->addButton("B1", false, 44, 44);
	//gui->addButton("B2", false);
	//
	//gui->addWidgetDown(new ofxUISlider(304,16,0.0,255.0,100.0,"BACKGROUND VALUE"));
	//gui->addSlider("slider",100,200,150,200,180); 
	//gui->addWidgetDown(new ofxUIToggle(32, 32, false, "FULLSCREEN"));//�л���ť


	//����ȡɫ��
	colorPicker = new ofxUICanvas(800,0,400,600);//���Ӳ��� ��������Ӧ ���˾����Ǹ���С �����Ļᱻ�ü�
	colorPicker->addLabel("MyProject4", OFX_UI_FONT_LARGE);//�����
	colorPicker->addFPSSlider("FPS SLIDER",200, 5, 100);//֡�ʼ��
	colorPicker->addLabel("colorPicker");
	colorPicker->addSpacer();//�ָ��� ���Ը��ݲ���������
	red = 0;
	green = 0;
	blue = 0;
	alpha = 255;
	brushScale = 20.0/100.0;//����.0��������int
	//cout<<brushScale*255<<endl;
	colorPicker->addSlider("red",0,255,red,200,20);
	colorPicker->addSlider("green",0,255,green,200,20);
	colorPicker->addSlider("blue",0,255,blue,200,20);
	colorPicker->addSlider("alpha",0,255,alpha,200,20);
	colorPicker->addLabel("BrushScale",OFX_UI_FONT_SMALL);
	colorPicker->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);//�ĳ�������
	colorPicker->addCircleSlider("BrushScale",0,100,20,100);
	colorPicker->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN); //�ĳ�������
	//��ѡ��
	vector<string> names; 
	names.push_back("pen1");
	names.push_back("pen2");
	names.push_back("pen3");
	names.push_back("pen4");
	names.push_back("pen5");
	names.push_back("pen6");
	names.push_back("pen7");
	names.push_back("pen8");
	//colorPicker->addRadio("RADIO", names, OFX_UI_ORIENTATION_HORIZONTAL,20, 20); //��ѡ����Ҫ���ʵ���ÿ������
	ofxUIRadio *radio = (ofxUIRadio *) colorPicker->addWidgetDown(new ofxUIRadio(20,20, "RADIO", names, OFX_UI_ORIENTATION_VERTICAL)); 
	radio->activateToggle("pen1");//Ĭ�ϵ�һ��
	pen = 1;
	ofAddListener(colorPicker->newGUIEvent,this,&testApp::guiEvent);//�ڶ���Ŀֻ��Ҫ��һ�������Ϳ����� ������������
	//��ʼ��UI��ɫ
	colorPicker->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(red,green,blue,alpha));
	

	//��ʱ�����ʼ��
	this->tempCanvas.allocate(ofGetWindowWidth()-200,ofGetWindowHeight(),GL_RGBA);
		this->tempCanvas.begin();
	ofSetColor(255);
	ofRect(0,0,this->tempCanvas.getWidth(),this->tempCanvas.getHeight());
	this->tempCanvas.end();


	//��ʱ����
	this->tempBrush.allocate(ofGetWindowWidth()-200,ofGetWindowHeight(),GL_RGBA);
	//3d
	mesh.load("lofi-bunny.ply");
	//shader
	font.loadFont("type/verdana.ttf", 100, true, false, true, 0.4, 72);
	shader.load("shaders/noise.vert", "shaders/noise.frag");
}

//--------------------------------------------------------------
void testApp::update()
{
	ofBackground(0,0,0);//ˢ��

	////�����м�һ��͸����Բ
	//ofPushStyle(); 
	//ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	//ofSetColor(255,0,0,120);
	//ofCircle(ofPoint(ofGetWindowWidth()/2,ofGetWindowHeight()/2),50);
	//ofPopStyle(); 
	tempCanvas.begin();
	if(canDraw){

		switch(pen)
		{
		case 1:
			//glClearColor(0,0,0,0);
			//glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//����������ջ���
			ofPushStyle();
			{
				//һ��ʼ��alphaΪ255����*255��ܴ󳬳���255�ͱ�Ϊ0�� �����ڴ˾��� ����������ɫһ��ʼΪ0����û������

				if(alpha>1)alpha =1;
				
				ofSetColor(ofColor(red*255,green*255,blue*255,alpha*255));//͸���Ȳ����Ǹ��������ɫ���ǱȽϰ�
				glColorMask(true,true,true,false);//�ر�alpha
				//ofEnableBlendMode(OF_BLENDMODE_DISABLED);
				//ofEnableBlendMode(OF_BLENDMODE_ALPHA);//�����ʲô
				ofCircle(ofPoint(mouseX,mouseY),brushScale*100);

				glColorMask(true,true,true,true);

			}
			ofPopStyle();
			break;
		case 2:
			//cout<<"this is 2"<<endl;
			ofPushStyle();			// ������ɫ���÷�����
			ofSetColor(0, 0, 0);
			ofFill();
			// 100�Σ����ƻ����ٶ�
			for ( int i = 0; i < 100; i++ )	
			{
				pdraw.update();
				pdraw.render();
			}
			ofPopStyle();
			break;
		case 3:
			//cout <<"this is 3"<<endl;

			tempBrush.begin();
			glClearColor(0,0,0,0);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//����������ջ���
			ofPushStyle();	
			ofFill();
			for (int i = 0; i < 200; i++){
				ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255));
				ofRect(ofRandom(0,20),ofRandom(0,20),ofRandom(0,40),ofRandom(0,40));//û��������չ�Ŀռ� ��ֵ��û����
			}
			ofPopStyle();
			tempBrush.end();
			tempBrush.draw(mouseX-20,mouseY-20);
			break;
		case 4:
			//cout<<pen<<endl;
			tempBrush.begin();
			glClearColor(0,0,0,0);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//����������ջ���
			ofPushStyle();	
			ofFill();
			ofSetHexColor(0xe0be21);
			ofSetPolyMode(OF_POLY_WINDING_ODD);	// this is the normal mode
			ofBeginShape();
			ofVertex(200,135);
			ofVertex(15,135);
			ofVertex(165,25);
			ofVertex(105,200);
			ofVertex(50,25);
			ofEndShape();

			// alpha is usually turned off - for speed puposes.  let's turn it on!
			//ofEnableAlphaBlending();//���Ϻ���ô�кڿ飿
			ofSetColor(255,0,0,127);   // red, 50% transparent
			ofRect(0,0,100,33);
			//ofDisableAlphaBlending();

			ofSetHexColor(0x000000);
			ofDrawBitmapString("ofSetColor(255,0,0,127)",0,0);//�����壿
			ofPopStyle();
			tempBrush.end();
			tempBrush.draw(mouseX-20,mouseY-20);
			break;
		case 5:
			//����ģ�����ࣿ
			tempBrush.begin();
			glClearColor(0,0,0,0);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//����������ջ���
			ofPushStyle();

			cam.begin();
			glPointSize(3);
			ofSetLineWidth(1);
			ofSetColor(ofColor::gray);
			mesh.drawWireframe();
			ofSetColor(ofColor::green);
			mesh.drawVertices();
			//mesh.drawFaces();
			cam.end();{
				int aa = mesh.getNumVertices();//C2361: initialization of is skipped by 'default' lab  case�������������������� �Ӹ������ű�ס����
				for(int i = 0; i < aa; i++) {
					ofVec3f cur = cam.worldToScreen(mesh.getVertex(i));
				}
			}
			ofPopStyle();
			tempBrush.end();
			tempBrush.draw(mouseX-20,mouseY-20);
			break;
		case 6:
			tempBrush.begin();
			glClearColor(0,0,0,0);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//����������ջ���
			ofPushStyle();

			ofSetColor(245, 58, 135);
			ofFill();
			shader.begin();
			//we want to pass in some varrying values to animate our type / color 
			shader.setUniform1f("timeValX", ofGetElapsedTimef() * 0.1 );
			shader.setUniform1f("timeValY", -ofGetElapsedTimef() * 0.1 );

			//we also pass in the mouse position 
			//we have to transform the coords to what the shader is expecting which is 0,0 in the center and y axis flipped. 
			//shader.setUniform2f("mouse", mouseX, mouseY );

			//finally draw our text
			//cout<<ofRandom(-30,30)<<endl;
			font.drawStringAsShapes("OPEN", mouseX+ ofRandom(-30,30), mouseY);
			shader.end();



			ofPopStyle();
			tempBrush.end();
			tempBrush.draw(mouseX-20,mouseY-20);
			break;
			break;
		default:
			break;
		}

	}

	tempCanvas.end();
	
	
	
}

//--------------------------------------------------------------
void testApp::draw()
{
	tempCanvas.draw(0,0);//����draw����ʾ��
}
//--------------------------------------------------------------

void testApp::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName(); 
	int kind = e.widget->getKind(); 
	//switch���������Ǳ������� ��֧��string
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
	}else if(name == "pen1")
	{
		pen=1;
	}else if(name == "pen2")
	{
		pen=2;
	}else if(name == "pen3")
	{
		pen=3;
	}else if(name == "pen4")
	{
		pen=4;
	}else if(name == "pen5")
	{
		pen=5;
	}else if(name == "pen6")
	{
		pen=6;
	}else if(name == "pen7")
	{
		pen=7;
	}else if(name == "pen8")
	{
		pen=8;
	}
	//һ��ʼ��alphaΪ255����*255��ܴ󳬳���255�ͱ�Ϊ0�� �����ڴ˾��� ����������ɫһ��ʼΪ0����û������
	if(alpha>1)alpha =1;
	//������ɫ
	colorPicker->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(red*255,green*255,blue*255,alpha*255));
}
//--------------------------------------------------------------
void testApp::exit()
{
	//gui->saveSettings("GUI/guiSettings.xml");//�ر�ʱ����UI��Ϣ
	//delete gui;
	delete colorPicker;
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
			colorPicker->setDrawWidgetPadding(drawPadding);          
		}
		break;

	case 'h':
		{
			colorPicker->toggleVisible(); //�л��ɼ�
		}
		break; 
	case 'f':
		{
			ofToggleFullscreen(); 
			//ofSetFullscreen(true);
			ofSetupScreen();
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
	if(button == 0){
	//����2��
	pdraw.get_sampler_per_time(x, y);}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
	if(button == 0)//���
	{canDraw = true;
	//����2��
	pdraw.get_sampler_per_time(x, y);
	}
	
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