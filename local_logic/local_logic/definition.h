#ifndef DEFINITION_H
#define DEFINITION_H

typedef double TSpeed;
typedef double TResourceD;
typedef int TResourceI;
typedef double TLength;

const TSpeed BASE_LEARN_ABILITY[5]{ 1,1.5,2,2.5,3 };
const TResourceI STUDENT_STAGE[4]{ 10,40,80,150 };
const TResourceI MAX_RESOURCE = 200;
const int NO_DATA = -1;

enum TentacleStatus
{
	Extending           //延伸中
	,Backing            //退后中（被打退）
	,Confrontation      //对峙中
	,Arrived            //已到达目的地
	,AfterCut           //被切断
	,Finished           //已经结算完毕，消失
};

#endif // DEFINITION_H