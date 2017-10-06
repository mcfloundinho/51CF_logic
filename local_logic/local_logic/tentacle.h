#ifndef TENTACLE_H
#define TENTACLE_H
#include "definition.h"
#include "object.h"

//用来表示对目标同学结算效果的临时变量
struct TransEffect
{
	TId m_targetStudent;
	TId m_
	TResourceD m_amount;
	
};

class Tentacle:public Object<Tentacle>
{
private:
	const TId m_sourceStudent;              //源同学
	const TId m_targetStudent;              //目标同学
	TentacleStatus m_status;                //触手状态
	const TLength m_length;                 //触手长度（由源/目标决定）
	TResourceI m_resource;                  //当前资源      （切断前有效）
	TResourceI m_frontResource;             //切断后前方资源（切断后有效）
	TResourceI m_backResource;              //切断后后方资源（切断后有效）

public:
	//新建触手
	Tentacle(TId source, TId target);
	//切断触手，position为从源细胞算起的资源数，返回值表示是否成功
	bool cut(int position);
	//
};

#endif // !TENTACLE_H