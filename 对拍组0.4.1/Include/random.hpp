// Please open with utf-8
#ifndef RANDOM
#define RANDOM

#include<random>

namespace RANDOM_NAMESPACE
{
	using namespace std;
	mt19937_64 randomer;
	bool uninit=1;
	
	inline void init()
	{
		random_device seed;
		randomer.seed(seed());
	}
	
	inline long long random(long long l,long long r)
	/*
	inline long long int random(long long int l,long long int r)
	作用: 随机生成 l ~ r 的数
	参数:
		- long long int l: 生成数下界
		- long long int r: 生成数上界
	时间复杂度: O(1)
	空间复杂度: O(1)
	注意事项:
		- l 和 r 应在 long long int 范围内
		- 对于错误的参数, 后果不可预测
	返回值: 生成的数
	*/
	{
		if(uninit)
			init(),
			uninit=0;
		return randomer()%(r-l+1)+l;
	}
}
using RANDOM_NAMESPACE::init;
using RANDOM_NAMESPACE::random;

#endif