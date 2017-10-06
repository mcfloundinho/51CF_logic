#ifndef DEFINITION_H
#define DEFINITION_H

typedef double TSpeed;
typedef double TResourceD;
typedef int TResourceI;
typedef double TLength;

const TSpeed BASE_LEARN_ABILITY[5]{ 1,1.5,2,2.5,3 };
const TResourceI STUDENT_STAGE[4]{ 10,40,80,150 };
const TResourceI MAX_RESOURCE = 200;

enum TentacleStatus
{
	extending           //延伸中
	,backing            //退后中
	,confrontation      //对峙中
	,arrived            //已到达目的地
	,cut                //被切断
	,finished           //已经结算完毕，消失
};

#endif // DEFINITION_H