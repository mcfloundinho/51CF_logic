#include"map.h"
#include<fstream>
#include<iostream>

bool Map::init()
{	
	ifstream inMap(id.c_str(),ios_base::binary);
	if (!inMap)
	{
		cout << "can't open the map file" << endl;
		return false;
	}

	inMap >> m_height;
	inMap >> m_width;

	int studentNum;
	inMap >> studentNum;
	TPoint _point;		
	for (int i = 0; i < studentNum; i++)
	{
		inMap >> _point.m_x;
		inMap >> _point.m_y;
		_point.m_state = Normal;
		m_studentPos.push_back(_point);
	}

	int barrierNum;
	TPoint beginP, endP;
	TBarrier _barrier;
	inMap >> barrierNum;
	for (int i = 0; i < barrierNum; i++)
	{
		inMap >> beginP.m_x;
		inMap >> beginP.m_y;
		beginP.m_state = Barrier;
		inMap >> endP.m_x;
		inMap >> endP.m_y;
		endP.m_state = Barrier;

		_barrier.m_beginPoint = beginP;
		_barrier.m_endPoint = endP;
		m_barrier.push_back(_barrier);
	}
	return true;
}