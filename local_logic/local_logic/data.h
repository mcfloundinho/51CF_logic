#ifndef _DATA_H
#define _DATA_H
/*  
**  Data结构体
**  用于数据的存储和共享    
**  在外部存储相关类只需存储 ID 在 Data 中调用
*/
#include<vector>
#include "student.h"
#include "tentacle.h"
#include "map.h"
#include "player.h"
using std::vector;
namespace DATA {
	struct Data
	{
		static vector<Student>  students;
		static vector<Tentacle> tentacles;
		static vector<Player>   players;
		//static Map              gameMap1;
	};
}

#endif // !_DATA_H