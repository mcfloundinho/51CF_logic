#pragma once

#ifndef  STUDENT_H_
#define  STUDENT_H_

#include"object.h"
#include<vector>
#include"tentacle.h"
#include"definition.h"
using namespace std;


struct StudentProperty
{
   TLA m_minLA;
   TLA m_maxLA;
   int m_maxTentacleNum;  //最大触手数量
   TSpeed m_regenarationSpeed;  //再生速度
};


class Student:public Object<Student>
{
public:
	Student();
	~Student();
	Student(const Student &);
	inline  StudentType    getStudentType();
    inline  void           setStudentType(const StudentType & _type);
	inline  TStudentID     getId();
	inline  void           setId( TStudentID _id);
	inline  TLA            getLeftLA();
	inline  void           setLeftLA(TLA);
	inline  TCamp          getCamp();
	inline  void           setCamp(TCamp _camp);
	inline  TPoint          getPos();
	inline  void           setPos(const TPoint& _point);
	inline  void           setOccupyLA(TLA _LA);
	inline  TLA            getOccupyLA();

	bool    LAempty();                  //学力值是否减为0

	void    addLA();                    //每一回合后的再生资源
	void    reduceLAForAttacked();      //因为被攻击而减少学力值，可遍历攻击自己的学生vector来计算
	void    reduceLAForstalemate();     //因为对峙而减少学力值,通过遍历自己的触手vector来计算 
	bool    addTentacle(const TCamp &,const TStudentID&);  //增加触手,学力不够返回false
	bool    cutTentacle(int _id, const TPosition &);       //在某一个点砍断触手，点无效则砍断操作无效,返回bool

private:
	StudentType      m_studentType;      //学生种类，大佬等 int
	TCamp            m_camp;             //所属阵营  int
	TStudentID       id;                 //学生id   int
	TLA              m_leftLA;           //剩余学力值
	TPoint            m_position;         //所在点的位置等信息
	TLA              m_occupyLA;         //中立同学的占有值
	vector<Tentacle> m_preTentacle;      //当前伸出去的触手
	vector<Student>  m_attackedBy;       //正在被被哪些同学攻击
	
};

#endif // STUDENT_H_