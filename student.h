#pragma once

#ifndef  STUDENT_H_
#define  STUDENT_H_

#include"object.h"
#include<vector>
using namespace std;


typedef int   TStudentID ;
typedef int   TLA;
typedef int   TPosition;
typedef int   TCamp;
typedef float TRegenarationSpeed;

class Tentacle;
class Point;
class Tentacle;


enum PointState {NORMAL,BARRIER,DISABLED};
struct Point
{
	TPosition  m_x;
	TPosition  m_y;
	PointState m_state;
};


enum StudentType  { XIANYU,XUEZHA,XUEBA,DALAO,JULAO,NEUTRAL};  //学生种类的枚举

struct StudentProperty
{
   TLA m_minLA;
   TLA m_maxLA;
   int m_maxTentacleNum;  //最大触手数量
   TRegenarationSpeed m_regenarationSpeed;  //再生速度
};


class Student:public Object<Student>
{
public:
	Student();
	~Student();
	Student(const Student &);
	inline  StudentType    m_getStudentType();
    inline  void           m_setStudentType(const StudentType & _type);
	inline  TStudentID     m_getId();
	inline  void           m_setId( TStudentID _id);
	inline  TLA            m_getLeftLA();
	inline  void           m_setLeftLA(TLA);
	inline  TCamp          m_getCamp();
	inline  void           m_setCamp(TCamp _camp);
	inline  Point          m_getPos();
	inline  void           m_setPos(const Point& _point);
	inline  void           m_setOccupyLA(TLA _LA);
	inline  TLA            m_getOccupyLA();

	bool    m_LAempty();                  //学力值是否减为0

	void    m_addLA();                    //每一回合后的再生资源
	void    m_reduceLAForAttacked();      //因为被攻击而减少学力值，可遍历攻击自己的学生vector来计算
	void    m_reduceLAForstalemate();     //因为对峙而减少学力值,通过遍历自己的触手vector来计算 
	bool    m_addTentacle(const TCamp &,const TStudentID&);  //增加触手,学力不够返回false
	bool    m_cutTentacle(int _id, const TPosition &);       //在某一个点砍断触手，点无效则砍断操作无效,返回bool

private:
	StudentType      m_studentType;      //学生种类，大佬等 int
	TCamp            m_camp;             //所属阵营  int
	TStudentID       id;                 //学生id   int
	TLA              m_leftLA;           //剩余学力值
	Point            m_position;         //所在点的位置等信息
	TLA              m_occupyLA;         //中立同学的占有值

	vector<Tentacle> m_preTentacle;      //当前伸出去的触手
	vector<Student>  m_attackedBy;       //正在被被哪些同学攻击
	
};

#endif // STUDENT_H_