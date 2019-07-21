#include "text.h"
#include "ofTypes.h"
#include "math.h"
text::text()
{
	char filePath[256];
	sprintf(filePath, "data/msyh.ttf");
	myFont = new FTGLPolygonFont(filePath);
	myFont->FaceSize(21);
	flag=0;
	dx=0;
	dy=0;

	

}
void text::init(int pos_centerX,int pos_centerY,int text_num ){
	circleNum=text_num;
	center.x=pos_centerX;
	center.y=pos_centerY;
	myText=new wstring[circleNum];
	points=new ofPoint[circleNum]; 
	degree=new float[circleNum];
	degree2=new float[circleNum];
	for (int i=0;i<circleNum;i++)
	{
		myText[i]=Text.substr(i,1).c_str();
		//points[i].x=0;
		//points[i].y=0;
	}

	endPoints=new ofPoint[circleNum];//圓圈num等份邊緣點
	for (int i=0;i<circleNum;i++)
	{
		endPoints[i].x=0;
		endPoints[i].y=0;
	}
//按每行15个字算！
	for (int i=0;i<=text_num/15;i++)
	{  
		if (i<text_num/15)
		{
		    for (int j=0;j<15;j++)
		    {
		    	myText[i*15+j]=Text.substr(i*15+j,1).c_str();
		    	points[i*15+j].x=pos_centerX+j*21.0f-15*21/2.0;
		    	points[i*15+j].y=pos_centerY-75.0f+i*30;
	     	}
		}
		else
		{
			for (int j=0;j<text_num%15;j++)
			{
				myText[i*15+j]=Text.substr(i*15+j,1).c_str();
				points[i*15+j].x=pos_centerX+j*21.0f-15*21/2.0;
				points[i*15+j].y=pos_centerY-75.0f+i*30;
			}

		}
		
	}

	for (int i=0;i<circleNum;i++)
	{   
		float ran=ofRandom(0,3.14*2);
		endPoints[i].x=center.x+2*((50.0+ofRandom(0,40))*cos(ran));
		endPoints[i].y=center.y+2*((50.0+ofRandom(0,40))*sin(ran));
	}

	for (int i=0;i<circleNum;i++)
	{//初始化定位字体显示方向，字的正方向始终与运行方向一致！
		if (endPoints[i].y>=center.y)
		{
			if (endPoints[i].x>=center.x)
				degree[i]=90+(acos(pow((endPoints[i].x-center.x),2)/(pow((endPoints[i].x-center.x),2)+pow((endPoints[i].y-center.y),2)))*180)/3.14;
			else
				degree[i]=180+(acos(pow((endPoints[i].x-center.x),2)/(pow((endPoints[i].x-center.x),2)+pow((endPoints[i].y-center.y),2)))*180)/3.14;
		}
		else{
			if (endPoints[i].x>=center.x)
				degree[i]=(acos(pow((endPoints[i].x-center.x),2)/(pow((endPoints[i].x-center.x),2)+pow((endPoints[i].y-center.y),2)))*180)/3.14;
			else
				degree[i]=-90+(acos(pow((endPoints[i].x-center.x),2)/(pow((endPoints[i].x-center.x),2)+pow((endPoints[i].y-center.y),2)))*180)/3.14;
		}
		if (points[i].y>=endPoints[i].y)
		{
			if (points[i].x>=endPoints[i].x)
				degree2[i]=90+(acos(pow((points[i].x-endPoints[i].x),2)/(pow((points[i].x-endPoints[i].x),2)+pow((points[i].y-endPoints[i].y),2)))*180)/3.14;
			else
				degree2[i]=180+(acos(pow((points[i].x-endPoints[i].x),2)/(pow((points[i].x-endPoints[i].x),2)+pow((points[i].y-endPoints[i].y),2)))*180)/3.14;
		}
		else{
			if (points[i].x>=endPoints[i].x)
				degree2[i]=(acos(pow((points[i].x-endPoints[i].x),2)/(pow((points[i].x-endPoints[i].x),2)+pow((points[i].y-endPoints[i].y),2)))*180)/3.14;
			else
				degree2[i]=-90+(acos(pow((points[i].x-endPoints[i].x),2)/(pow((points[i].x-endPoints[i].x),2)+pow((points[i].y-endPoints[i].y),2)))*180)/3.14;
		}
		
	}
	
}

text::~text(void)
{
}
void text::drawCharacter(float x,float y,wstring str,float degrees){

	ofPushMatrix();
	ofTranslate(x-9,y-9);
	ofRotateZ(degrees);
	glScalef(1, -1, 1);
	myFont->Render(str.c_str());
	ofPopMatrix();

}
void text::drawText(){


	if (flag<80&&flag>=0)
	{
	  
	
	for (int i=0;i<circleNum;i++)
	{   
		if (flag>=0&&flag<=60){
	    dx =sqrt((float)flag)*(0.9)*(endPoints[i].x-center.x)/sqrt(60.0);
		dy =sqrt((float)flag)*(0.9)*(endPoints[i].y-center.y)/sqrt(60.0);
		float   Character_posx=center.x+(dx);
		float   Character_posy=center.y+(dy);
		drawCharacter(Character_posx,Character_posy,myText[i],degree[i]);
		}
		 
		if (flag>60&&flag<80){
			dx =sqrt((float)(flag-60))*(0.1)*(endPoints[i].x-center.x)/sqrt(60.0);
			dy =sqrt((float)(flag-60))*(0.1)*(endPoints[i].y-center.y)/sqrt(60.0);
			float   Character_posx=center.x+(endPoints[i].x-center.x)*0.9+(dx);
			float   Character_posy=center.y+(endPoints[i].y-center.y)*0.9+(dy);
			drawCharacter(Character_posx,Character_posy,myText[i],degree[i]);
		}
		
	}
	
	}

	if (flag>=80&&flag<140)
		{
			for (int i=0;i<circleNum;i++){
				float dx=((float)(flag-80))*(points[i].x-endPoints[i].x)/60.0;
				float dy=((float)(flag-80))*(points[i].y-endPoints[i].y)/60.0;
				drawCharacter(endPoints[i].x+dx,endPoints[i].y+dy,myText[i],degree2[i]);
			
	}
	}
	flag++;
	if (flag>=140)
	{
		flag=140;
		for (int i=0;i<circleNum;i++){
			float dx=((float)(flag-80))*(points[i].x-endPoints[i].x)/60.0;
			float dy=((float)(flag-80))*(points[i].y-endPoints[i].y)/60.0;
			drawCharacter(endPoints[i].x+dx,endPoints[i].y+dy,myText[i],0);
		}
}

	
}