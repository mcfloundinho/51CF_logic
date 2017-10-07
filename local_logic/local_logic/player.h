#ifndef PLAYER_H
#define PLAYER_H

#include "definition.h"
#include "object.h"
#include "vector"


class Student;

class Player :public Object<Player>
{
private:
	std::vector<TId> m_students;         //所属同学
	TDepartment m_department;            //院系种类
	TResourceD m_technologyPoint = 0.0;        //科技点数

	TLevel m_RegenerationSpeedLevel = 0;      //再生倍率等级
	TLevel m_ExtendingSpeedLevel = 0;      //延伸速度等级
	TLevel m_ExtraControlLevel = 0;        //额外操作数等级
	TLevel m_DefenceLevel = 0;       //防御等级

	TRound m_skillLeftRound = 0;       //剩余主动技能回合
	std::size_t m_maxControlNumber;    //最大控制数

	bool m_hacked = false;                //是否被黑
	bool m_alive = true;                  //是否还活着

	//升级各种被动属性，返回是否成功
	bool _updateRegeneration();
	bool _updateExtending();
	bool _updateExtraControl();
	bool _updateDefence();

public:

	void addStudent(TId student);             //增加同学
	void removeStudent(TId student);          //减少同学
	void setHacked(bool isHacked);            //设置是否被黑
	bool update(TPlayerProperty property);    //升级    
	void addTechPoint();                      //根据当前细胞增加科技点数

	//得到各种量

	bool isHacked();
	bool isAlive();
	TResourceD techPoint();
	std::vector<TId> getStudents();
	std::size_t maxControlNumber();
	TDepartment getDepartment();
	TLevel regenerationSpeedLevel();
	TLevel extendingSpeedLevel();
	TLevel extraControlLevel();
	TLevel defenceLevel();
	TRound skillLeftRound();
};

#endif // PLAYER_H
