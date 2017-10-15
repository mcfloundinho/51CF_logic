#include "player.h"
#include "data.h"
using namespace DATA;

bool Player::_upgradeRegeneration()
{
	//已经升到最高级直接返回
	if (m_RegenerationSpeedLevel == MAX_REGENERATION_SPEED_LEVEL)
		return false;
	//科创点数不够直接返回
	if (m_technologyPoint < RegenerationSpeedUpdateCost[m_RegenerationSpeedLevel])
		return false;

	//升级
	m_technologyPoint -= RegenerationSpeedUpdateCost[m_RegenerationSpeedLevel];
	m_RegenerationSpeedLevel++;
	return true;
}

bool Player::_upgradeExtending()
{
	//已经升到最高级直接返回
	if (m_ExtendingSpeedLevel == MAX_EXTENDING_SPEED_LEVEL)
		return false;
	//科创点数不够直接返回
	if (m_technologyPoint < ExtendingSpeedUpdateCost[m_ExtendingSpeedLevel])
		return false;

	//升级
	m_technologyPoint -= ExtendingSpeedUpdateCost[m_ExtendingSpeedLevel];
	m_ExtendingSpeedLevel++;
	return true;
}

bool Player::_upgradeExtraControl()
{
	//已经升到最高级直接返回
	if (m_ExtraControlLevel == MAX_EXTRA_CONTROL_LEVEL)
		return false;
	//科创点数不够直接返回
	if (m_technologyPoint < ExtraControlStageUpdateCost[m_ExtraControlLevel])
		return false;

	//升级
	m_technologyPoint -= ExtraControlStageUpdateCost[m_ExtraControlLevel];
	m_ExtraControlLevel++;
	return true;
}

bool Player::_upgradeDefence()
{
	//已经升到最高级直接返回
	if (m_DefenceLevel == MAX_DEFENCE_LEVEL)
		return false;
	//科创点数不够直接返回
	if (m_technologyPoint < DefenceStageUpdateCost[m_DefenceLevel])
		return false;

	//升级
	m_technologyPoint -= DefenceStageUpdateCost[m_DefenceLevel];
	m_DefenceLevel++;
	return true;
}

void Player::addStudent(TId student)
{
	m_students.push_back(student);
}

void Player::removeStudent(TId student)
{
	for (int i = 0; i != m_students.size(); ++i)
		if (m_students[i] == student)
			m_students.erase(m_students.begin() + i);
}

void Player::setHacked(bool isHacked)
{
	m_hacked = isHacked;
}

bool Player::upgrade(TPlayerPowerProperty property)
{
	switch (property)
	{
	case RegenerationSpeed:
		return _upgradeRegeneration();
		break;
	case ExtendingSpeed:
		return _upgradeExtending();
		break;
	case ExtraControl:
		return _upgradeExtraControl();
		break;
	case Defence:
		return _upgradeDefence();
		break;
	default:
		break;
	}
}

void Player::addTechPoint()
{
	for (TId StuId : m_students)
		m_technologyPoint += Data::students[StuId].getStudentProperty().m_techSpeed;
}

void Player::Kill()
{
	m_alive = false;
}