#include"map.h"
#include<fstream>
#include<iostream>
#include "data.h"
#include "student.h"
#include "player.h"
#include "tentacle.h"

Map::Map(DATA::Data* _data):data(_data)
{
}

bool Map::init(TMapID filename)  //通过文件初始化信息
{	
	setID(filename);
	ifstream inMap(filename,ios_base::binary);
	if (!inMap)
	{
		cerr << "can't open the map file" << endl;
		return false;
	}

	//初始化地图
	inMap >> m_height;
	inMap >> m_width;

	int barrierNum;
	TPoint beginP, endP;
	TBarrier _barrier;
	inMap >> barrierNum;
	for (int i = 0; i < barrierNum; i++)
	{
		inMap >> beginP.m_x;
		inMap >> beginP.m_y;
		//beginP.m_state = Barrier;
		inMap >> endP.m_x;
		inMap >> endP.m_y;
		//endP.m_state = Barrier;

		_barrier.m_beginPoint = beginP;
		_barrier.m_endPoint = endP;
		m_barrier.push_back(_barrier);
	}

	//初始化阵营
	int campNum;
	inMap >> campNum;
	int _department;
	int stuNum,_tempid;
	vector<TStudentID> _stu;
	for (int i = 0; i < campNum; i++)
	{
		inMap >> _department >> stuNum;
		for (int i = 0; i != stuNum; ++i)
		{
			inMap >> _tempid;
			_stu.push_back(_tempid);
		}
		Player player(data, static_cast<TDepartment>(_department), _stu);
		data->players.push_back(player);
		_stu.clear();   //清空方便循环复用
	}

	//初始化学生
	int studentNum;
	inMap >> studentNum;
	TPoint _point;
	TCamp _camp; //阵营
	TResourceD _resource;
	bool special;
	TResourceD _techPoint;

	for (int i = 0; i < studentNum; i++)
	{
		inMap >> _point.m_x;
		inMap >> _point.m_y;
		_point.m_state = Normal;
		m_studentPos.push_back(_point);

		inMap >> _camp >> _resource >> special;
		if (special)
			inMap >> _techPoint;
		Student stu(data, _point, _camp, _resource, special, _techPoint);
		data->students.push_back(stu);
	}

	inMap.close();
	return true;
}
