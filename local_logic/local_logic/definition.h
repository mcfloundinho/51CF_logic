#ifndef DEFINITION_H
#define DEFINITION_H

typedef double TSpeed;
typedef double TResourceD;
typedef int    TResourceI;
typedef double TLength;
typedef int    TStudentID ;
typedef int    TLA;
typedef int    TPosition;
typedef int    TCamp;
typedef int    TMap;
typedef int    TMapID;

const TSpeed     BASE_LEARN_ABILITY[5]{ 1,1.5,2,2.5,3 };
const TResourceI STUDENT_STAGE[4]{ 10,40,80,150 };
const TResourceI MAX_RESOURCE = 200;
const int        NO_DATA = -1;

enum TentacleStatus
{
	Extending           //延伸中
	,Backing            //退后中（被打退）
	,Confrontation      //对峙中
	,Arrived            //已到达目的地
	,AfterCut           //被切断
	,Finished           //已经结算完毕，消失
};

enum PointState
 {
	 Normal,
	 Barriar,
	 Disables
};

struct Point
{
	TPosition  m_x;
	TPosition  m_y;
	PointState m_state;
};


enum StudentType  //学生种类的枚举
{ 
     XianYu,
	 XueZha,
	 XueBa,
	 DaLao,
	 JuLao,
	 Neutral;
};  

#endif // DEFINITION_H