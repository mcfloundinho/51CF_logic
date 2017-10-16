#pragma once

#ifndef  STUDENT_H_
#define  STUDENT_H_

#include"object.h"
#include<vector>
#include"tentacle.h"
#include"definition.h"
#include <iostream>
namespace DATA
{
	class Data;
}
using namespace std;


struct StudentProperty
{
   //TLA m_minLA;
   //TLA m_maxLA;
   int m_maxTentacleNum;  //最大触手数量
   TSpeed m_regenarationSpeed;  //再生速度
   TSpeed m_techSpeed;    //科创点数
   bool m_special;        //是否是特殊细胞/tech再生与LA再生是否关联
};


class Student:public Object<Student>
{
public:
	//Student();    不提供默认构造函数
	Student(DATA::Data* _data,TPoint pos, TCamp campid, TResourceD resource, bool special, TSpeed techPoint);
	~Student();
	Student(const Student &) = default;
	/*
	inline  const StudentType    getStudentType()const;
    inline  void                 setStudentType(const StudentType & _type);
	inline  const TStudentID     getId()const;
	inline  void                 setId( TStudentID _id);
	inline  const TLA            getLeftLA()const;
	inline  void                 setLeftLA(TLA);
	inline  const TCamp          getCamp()const;
	inline  void                 setCamp(TCamp _camp);
	inline  const TPoint         getPos() const;
	inline  void                 setPos(const TPoint& _point);
	inline  void                 setOccupyLA(TLA _LA);
	inline  const TLA            getOccupyLA() const;


	bool    LAempty();                  //学力值是否减为0
	*/
	//Student(StudentType);
	
	inline  TResourceD              getLeftLA()           const { return m_resource;     }
	//inline  TStudentID       getId()               const { return id;           }
	inline  TCamp            getCampID()           const { return m_campID;       }
	inline  TPoint           getPos()              const { return m_position;   }
	inline  TResourceD              getOccupyLA()         const { return m_occupyPoint;   }
	inline  StudentType      getStudentType()      const { return m_studentType;}
	inline  StudentProperty& getStudentProperty()        { return m_property;   }
	inline  vector<TId>&      getTentacles() { return m_preTentacle; }
	inline  vector<TId>&      attackedBy() { return m_attackedBy; }

	inline  void             setOccupyLA(TResourceD _LA)    { m_occupyPoint = _LA; }
	//inline  void             setId(TStudentID _id)   { id = _id;         }
	inline  void             setResource(TResourceD _la)      { m_resource = _la;   }
	inline  void             setCampID(TCamp _camp)  { m_campID = _camp; }
	inline  void             setStudentType(const StudentType & _type) { m_studentType = _type; }
	inline  void             setPos(const TPoint& _point)              { m_position = _point;   }

	bool    resourceEmpty()     { return m_resource <= 0; }                  //学力值是否减为0
	

	void    addLA();                    //每一回合后的再生资源
	//void    moveTentacle();             //移动自己的触手，资源归零将切断
	//void    reduceLAForAttacked();      //因为被攻击而减少学力值，可遍历攻击自己的学生vector来计算
	//void    reduceLAForstalemate();     //因为对峙而减少学力值,通过遍历自己的触手vector来计算 
	bool    addTentacle(const TStudentID&);  //增加触手,学力不够返回false
	bool    cutTentacle(TId _id, TPosition pos);       //在某一个点砍断触手，点无效则砍断操作无效,返回bool
	void    updateProperty(bool special = false);            //根据当前资源更新属性

private:
	StudentType      m_studentType;      //学生种类，大佬等 int	
	StudentProperty  m_property;         //特点
//	TStudentID       id;                 //学生id   int

	TResourceD       m_resource;           //剩余学力值

	DATA::Data* const             data;             //共享数据
	TCamp            m_campID;           //所属阵营  int
	TPoint           m_position;         //所在点的位置等信息
	TResourceD              m_occupyPoint;         //中立同学的占有值
	vector<TTentacleID> m_preTentacle;   //当前伸出去的触手
	vector<TTentacleID> m_attackedBy;    //正在被被哪些触手攻击

};

#endif // STUDENT_H_