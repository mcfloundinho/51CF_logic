#ifndef MAP_H_
#define MAP_H_
#include<vector>
#include <string>
#include "definition.h"
using namespace std;
namespace DATA 
{
	class Data;
}


class Map:public BaseMap
{
public:
	Map(DATA::Data* _data);
	//~Map();

	//void   setWidth(TMap );
	//void   setHeiget(TMap );
	
	bool   init(TMapID filename);            //利用文件初始化当前地图,不成功返回false
private:
	DATA::Data* data;
};

#endif //_MAP_H_
