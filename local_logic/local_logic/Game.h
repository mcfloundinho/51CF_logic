#ifndef GAME_H
#define GAME_H

#include "definition.h"
#include "data.h"
#include <vector>
#include <string>
using std::vector; 
using std::string;
using std::size_t;


class Game
{
public:
	void init(string filename);//初始化信息
	void run();                //开始跑代码
	vector<Info>* generateInfo();
	//void Run(vector<vector<>>)
private:
	void Round();             //每个回合
	void skillPhase();         //技能阶段
	void regeneratePhase();    //恢复阶段
	void transPhase();         //传输/攻击阶段
	void killPlayer(TCamp id); //杀死玩家   
	vector<Info>* info;
	DATA::Data data;      //所有的数据存放处
	TRound currentRound;  //当前回合数
	size_t playerSize;    //游戏规模
	size_t playerAlive;   //存活人数
	vector<TStudentID> Rank;//根据总资源数排名
	TResourceI _MAX_RESOURCE_;//每局特定的最大资源
	vector<int> controlCount; //记录操作数
};

#endif // !GAME_H

