/**
 * @file LinkPenDrawer.h 
 * @author GeistYp
 */
#pragma once

#include "ofMain.h"
#include "ofVectorMath.h"
#define ofxVec2f ofVec2f
/**
 * @class LinkPenDrawer LinkPenDrawer.h
 * @brief 连线笔刷绘制
 */
class LinkPenDrawer
{
public:

	LinkPenDrawer()
	{
		flag_draw_start = false;

		vel_of_draw = 0.5;

		size_draw_factor = 100;

		size_lerp_factor = 0.1;

		sampler_delay = 1;

		cur_sampler_delay = 0;

	}

	// 采样延时计数
	int					cur_sampler_delay;

	// 采样延时时长
	int					sampler_delay;

	// 路径采样坐标列表
	vector<ofxVec2f>	root_sampler;

	// 是否开始更新绘制
	bool				flag_draw_start;

	// 当前绘制位置
	ofxVec2f			pos_of_draw;

	// 当前绘制大小
	float				size_of_draw;

	// 绘制点之间距离
	float				vel_of_draw;

	// 绘制点之间距离总时长
	int					times_of_drawball_move;

	// 线宽大小比例
	int					size_draw_factor;

	// 大小变化率
	float				size_lerp_factor;

	// 当前点位移量
	ofxVec2f			vel_change_of_segment;

	// 当前点大小变化量
	float				size_change_of_segment;

	// 当前移动的单位时长
	int					cur_times_of_move;

	// 当前移动的采样点ID
	int					cur_id_of_draw_point;

	// 采样坐标点，有采样延时设置sampler_delay
	// 第一次开始标志更新绘制开始
	void get_sampler_per_time(int x, int y)
	{
		if ( cur_sampler_delay++ < sampler_delay ) return;
		cur_sampler_delay = 0;

		root_sampler.push_back(ofxVec2f(x, y));

		// 两个点才开始绘制
		if ( !flag_draw_start )
		{
			trigger_draw_start();
		}

		cout<<root_sampler.size()<<endl;
	}

	// 释放所有采样点，关乎连线问题，若不是一笔到底，需要定时释放
	// 或者按照控制时长控制释放
	void release_sampler()
	{
		root_sampler.clear();

		flag_draw_start = false;

		//timespan_ticker = 0;

		cur_id_of_draw_point = 0;
	}

	// 触发绘制开始
	void trigger_draw_start()
	{
		flag_draw_start = true;

		cur_id_of_draw_point = 0;

		// 大小初始化
		size_of_draw = 0;

		comput_segment_properity();
	}

	// 触发下一段的绘制
	void trigger_draw_next()
	{
		comput_segment_properity();
	}

	// 计算段 绘制数据
	// 位移和目标大小
	void comput_segment_properity()
	{
		// 结束
		if ( cur_id_of_draw_point == root_sampler.size() - 1 )
		{
			cout<<"root sampler finished!"<<endl;

			flag_draw_start = false;

			return;
		}

		// 位置 初始化
		pos_of_draw = root_sampler[cur_id_of_draw_point];

		// 两点距离
		ofxVec2f dist = root_sampler[cur_id_of_draw_point+1] - root_sampler[cur_id_of_draw_point];

		// 移动次数
		times_of_drawball_move = (int)(dist.length() / vel_of_draw) + 1;

		cur_times_of_move = 0;

		// 计算 段间 距离变化值
		vel_change_of_segment = dist.getNormalized() * vel_of_draw;

		// 计算 段间 大小变化值
		//size_change_of_segment = (float)PENDRAWER_SIZE_FACTOR / (float)( times_of_drawball_move * times_of_drawball_move );
		// 快要结束
		if ( cur_id_of_draw_point == root_sampler.size() - 2 ) 
		{
			size_change_of_segment = 0;
		}
		else
			size_change_of_segment = (float)size_draw_factor / (float)( times_of_drawball_move );

		// 移除起始点
		if ( root_sampler.size() > 3 )
		{
			root_sampler.erase(root_sampler.begin());

			cur_id_of_draw_point--;
		}
	}

	// 更新绘制点数据
	// 到达下一目标点后，触发下一段计算
	void update()
	{
		if ( flag_draw_start )
		{
			pos_of_draw += vel_change_of_segment;
			//size_of_draw += size_change_of_segment;
			size_of_draw = ofLerp(size_of_draw, size_change_of_segment, size_lerp_factor);

			cur_times_of_move++;
			// 停止
			if ( cur_times_of_move == times_of_drawball_move ) 
			{
				cur_id_of_draw_point++;
				trigger_draw_next();
			}
		}
	}

	// 绘制目标点
	void render()
	{
		if ( flag_draw_start )
		{
			ofCircle(pos_of_draw.x, pos_of_draw.y, size_of_draw);
			//ofRect(pos_of_draw.x, pos_of_draw.y, size_of_draw, size_of_draw);
			//ofLine(pos_of_draw.x, pos_of_draw.y, pos_of_draw.x+3, pos_of_draw.y+size_of_draw);
		}
	}

	// TODO
	// 绘制采样点连线
	void draw_sampler()
	{
		glBegin(GL_LINE_STRIP);
		for ( int i = 0; i < root_sampler.size(); i++ )
		{
			glVertex2f(root_sampler[i].x, root_sampler[i].y);
		}
		glEnd();

		glPointSize(5);
		glBegin(GL_POINTS);
		for ( int i = 0; i < root_sampler.size(); i++ )
		{
			glVertex2f(root_sampler[i].x, root_sampler[i].y);
		}
		glEnd();

	}

};