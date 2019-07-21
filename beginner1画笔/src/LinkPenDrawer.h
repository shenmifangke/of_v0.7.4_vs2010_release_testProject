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
 * @brief ���߱�ˢ����
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

	// ������ʱ����
	int					cur_sampler_delay;

	// ������ʱʱ��
	int					sampler_delay;

	// ·�����������б�
	vector<ofxVec2f>	root_sampler;

	// �Ƿ�ʼ���»���
	bool				flag_draw_start;

	// ��ǰ����λ��
	ofxVec2f			pos_of_draw;

	// ��ǰ���ƴ�С
	float				size_of_draw;

	// ���Ƶ�֮�����
	float				vel_of_draw;

	// ���Ƶ�֮�������ʱ��
	int					times_of_drawball_move;

	// �߿��С����
	int					size_draw_factor;

	// ��С�仯��
	float				size_lerp_factor;

	// ��ǰ��λ����
	ofxVec2f			vel_change_of_segment;

	// ��ǰ���С�仯��
	float				size_change_of_segment;

	// ��ǰ�ƶ��ĵ�λʱ��
	int					cur_times_of_move;

	// ��ǰ�ƶ��Ĳ�����ID
	int					cur_id_of_draw_point;

	// ��������㣬�в�����ʱ����sampler_delay
	// ��һ�ο�ʼ��־���»��ƿ�ʼ
	void get_sampler_per_time(int x, int y)
	{
		if ( cur_sampler_delay++ < sampler_delay ) return;
		cur_sampler_delay = 0;

		root_sampler.push_back(ofxVec2f(x, y));

		// ������ſ�ʼ����
		if ( !flag_draw_start )
		{
			trigger_draw_start();
		}

		cout<<root_sampler.size()<<endl;
	}

	// �ͷ����в����㣬�غ��������⣬������һ�ʵ��ף���Ҫ��ʱ�ͷ�
	// ���߰��տ���ʱ�������ͷ�
	void release_sampler()
	{
		root_sampler.clear();

		flag_draw_start = false;

		//timespan_ticker = 0;

		cur_id_of_draw_point = 0;
	}

	// �������ƿ�ʼ
	void trigger_draw_start()
	{
		flag_draw_start = true;

		cur_id_of_draw_point = 0;

		// ��С��ʼ��
		size_of_draw = 0;

		comput_segment_properity();
	}

	// ������һ�εĻ���
	void trigger_draw_next()
	{
		comput_segment_properity();
	}

	// ����� ��������
	// λ�ƺ�Ŀ���С
	void comput_segment_properity()
	{
		// ����
		if ( cur_id_of_draw_point == root_sampler.size() - 1 )
		{
			cout<<"root sampler finished!"<<endl;

			flag_draw_start = false;

			return;
		}

		// λ�� ��ʼ��
		pos_of_draw = root_sampler[cur_id_of_draw_point];

		// �������
		ofxVec2f dist = root_sampler[cur_id_of_draw_point+1] - root_sampler[cur_id_of_draw_point];

		// �ƶ�����
		times_of_drawball_move = (int)(dist.length() / vel_of_draw) + 1;

		cur_times_of_move = 0;

		// ���� �μ� ����仯ֵ
		vel_change_of_segment = dist.getNormalized() * vel_of_draw;

		// ���� �μ� ��С�仯ֵ
		//size_change_of_segment = (float)PENDRAWER_SIZE_FACTOR / (float)( times_of_drawball_move * times_of_drawball_move );
		// ��Ҫ����
		if ( cur_id_of_draw_point == root_sampler.size() - 2 ) 
		{
			size_change_of_segment = 0;
		}
		else
			size_change_of_segment = (float)size_draw_factor / (float)( times_of_drawball_move );

		// �Ƴ���ʼ��
		if ( root_sampler.size() > 3 )
		{
			root_sampler.erase(root_sampler.begin());

			cur_id_of_draw_point--;
		}
	}

	// ���»��Ƶ�����
	// ������һĿ���󣬴�����һ�μ���
	void update()
	{
		if ( flag_draw_start )
		{
			pos_of_draw += vel_change_of_segment;
			//size_of_draw += size_change_of_segment;
			size_of_draw = ofLerp(size_of_draw, size_change_of_segment, size_lerp_factor);

			cur_times_of_move++;
			// ֹͣ
			if ( cur_times_of_move == times_of_drawball_move ) 
			{
				cur_id_of_draw_point++;
				trigger_draw_next();
			}
		}
	}

	// ����Ŀ���
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
	// ���Ʋ���������
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