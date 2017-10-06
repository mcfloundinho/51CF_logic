#ifndef DEFINITION_H
#define DEFINITION_H

typedef double TSpeed;
typedef double TResourceD;  //double 的资源数，用于内部操作
typedef int    TResourceI;  //int    的资源数，用于显示
typedef double TLength;
typedef int    TStudentID ;
typedef int    TLA;
typedef int    TPosition;
typedef int    TCamp;
typedef int    TMap;
typedef int    TMapID;
typedef int    TLevel;  //各项属性等级
typedef int    TRound;  //回合数
typedef double TPower;  //倍率

const TSpeed     BASE_LEARN_ABILITY[5]{ 1,1.5,2,2.5,3 };
const TResourceI STUDENT_STAGE[4]{ 10,40,80,150 };
const TResourceI MAX_RESOURCE = 200;
const int        NO_DATA = -1;

//最大技能等级
const TLevel MAX_REGENERATION_SPEED_LEVEL = 6;
const TLevel MAX_EXTENDING_SPEED_LEVEL = 6;
const TLevel MAX_EXTRA_CONTROL_LEVEL = 4;
const TLevel MAX_DEFENCE_LEVEL = 4;

//各技能等级对应数值
const TPower RegenerationSpeedStage[MAX_REGENERATION_SPEED_LEVEL] = { 1,1.05,1.1,1.15,1.2,1.25 };
const TPower ExtendingSpeedStage[MAX_EXTENDING_SPEED_LEVEL] = { 1,1.1,1.2,1.3,1.4,1.5 };
const TPower ExtraControlStage[MAX_EXTRA_CONTROL_LEVEL] = { 0,0.5,1,1.5 };
const TPower DefenceStage[MAX_DEFENCE_LEVEL] = { 1.5,1.4,1.3,1.2 };

enum TDepartment
{
	Aeronautics          //航院
	, Medical            //医学
	, Energy             //能源
	, Electronic         //电子
	, Economy            //经管
	, Computer           //计算机
	, Automation         //自动化
	, Environment        //环境
};

enum TPlayerProperty
{
	RegenerationSpeed    //再生速度
	, ExtendingSpeed //延伸速度
	, ExtraControl   //额外控制数
	, Defence        //防御等级
};

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
	Blocked,
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
	Neutral
};  

#endif // DEFINITION_H