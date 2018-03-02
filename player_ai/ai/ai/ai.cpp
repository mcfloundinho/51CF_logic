#include "ai.h"
#include "definition.h"
#include <iostream>
#include <vector>
void player_ai(Info* info)
{
	std::cout << "I'm in ai.dll!!!!!!!!!" << endl;
	info->myCommandList.addCommand(upgrade, { RegenerationSpeed });
}

void test(int a,int &b,int *c)
{
	std::cout << a << endl;
	std::cout << b++ << endl;
	std::cout << ((*c)++) << endl;
}

void test_vec(vector<int> a, vector<int> &b, vector<int> *c)
{
	a.push_back(1);
	b.push_back(2);
	c->push_back(3);
}