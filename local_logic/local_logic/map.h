#pragma once

#ifndef MAP_H_
#define MAP_h_
#include"student.h"
#include<vector>
using namespace std;

typedef  int TMap;
typedef  int TMapID;

class Tentacle;
class Player;

struct Barrier
{
	Point m_beginPoint;
	Point m_endPoing;
};

class Map
{
public:
	Map();
	~Map();
	TMap   getWidth()  const;
	TMap   getHeigth() const ;
	void   setWidth(TMap );
	void   setHeiget(TMap );
	
	bool   init();                        //利用文件初始化当前地图,不成功返回false
	bool   passable(Point p1,Point p2);   //判断触手能否连接这两个点
	bool   isOutside(Point );             //判断点是否越界
	
	const  vector<Point>  &  getStudentPos() const;
	const  vector<Barrier>&  getBarriar()    const;
private:
	TMapID            id;                  //记录地图的id，由game赋值，被init函数使用，选择对应的文件
	TMap              m_width;
	TMap              m_height;
	vector<Point>     m_studentPos;        //只设定细胞的坐标，之后的势力分配交给game
	vector<Barrier>   m_bariar; 

};

#endif
