#include"student.h"

Student::Student()
{
  
}

Student::~Student()
{}

Student::Student(StudentType _type)
{
	int type = _type;
	if (_type != Neutral)
	{
		m_property.m_minLA = STUDENT_STAGE[type];
		m_property.m_maxLA = STUDENT_STAGE[type + 1];
		m_property.m_maxTentacleNum = TENTACLE_NUMBER[type];
		m_property.m_regenarationSpeed = BASE_REGENERETION_SPEED[type];
	}
	else
	{
		//中立同学
	}

	//初始化的形式待定
	/*  
	id = ;
	m_camp = ;
	m_leftLA = ;
	m_position = ;
	m_occupyLA = ;
	m_preTentacle.clear();
	m_attackedBy.clear();
	*/
}

void Student::addLA()
{
	int level = m_data.players[m_campID].regenerationSpeedLevel();
	m_leftLA += RegenerationSpeedStage[level] * m_property.m_regenarationSpeed;
}

bool Student::addTentacle(const TStudentID& _id)
{
	//触手数量
	if (m_preTentacle.size() == m_property.m_maxTentacleNum)
	{
		cout << "the tentacle can't be more!";
		return false;
	}

	//新建

}