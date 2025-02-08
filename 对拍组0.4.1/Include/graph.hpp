// Please open with utf-8
#ifndef GRAPH
#define GRAPH

#include<vector>
#include<unordered_map>
#include<random.hpp>

namespace GRAPH_NAMESPACE
{
	using namespace std;
	
	unordered_map<int,int> fa;
	unordered_map<int,unordered_map<int,bool> > vis;
	
	inline int find(int u)
	{
		if(fa[u]==0)
			return fa[u]=u;
		if(fa[u]==u)
			return u;
		return fa[u]=find(fa[u]);
	}
	
	void wuxiangtu(int node,int edge,vector<int>Map[],bool liantong=0)
	/*
	void wuxiangtu(int node,int edge,vector<int>Map[],bool liantong)
	作用: 生成无向图
	参数:
		- int node: 生成的图有多少个点
		- int edge: 生成的图有多少条边
		- vector<int>Map[]: 存储生成的图的邻接表
		- bool liantong: 生成的图是否联通
	时间复杂度: 最低 O(edge), 平均 O(edge), 无最高上限(取决于生成时出现重边的次数)
	空间复杂度: O(edge)
	注意事项:
		- 对于错误的参数, 后果不可预测
	返回值: void
	*/
	{
		fa.clear();
		vis.clear();
		if(liantong)
		{
			for(int i=1;i<=node-1;++i)
			{
				int u=random(1,node),v=random(1,node);
				while(find(u)==find(v))
					u=random(1,node),v=random(1,node);
				vis[u][v]=vis[v][u]=1;
				Map[u].push_back(v);
				Map[v].push_back(u);
			}
			edge-=node-1;
		}
		for(int i=1;i<=edge;++i)
		{
			int u=random(1,node),v=random(1,node);
			while(u==v||vis[u][v])
				u=random(1,node),v=random(1,node);
			vis[u][v]=vis[v][u]=1;
			Map[u].push_back(v);
			Map[v].push_back(u);
		}
	}
	
	void youxiangtu(int node,int edge,vector<int>Map[])
	/*
	void youxiangtu(int node,int edge,vector<int>Map[],bool liantong)
	作用: 生成有向图
	参数:
		- int node: 生成的图有多少个点
		- int edge: 生成的图有多少条边
		- vector<int>Map[]: 存储生成的图的邻接表
	时间复杂度: 最低 O(edge), 平均 O(edge), 无最高上限(取决于生成时出现重边的次数)
	空间复杂度: O(edge)
	注意事项:
		- 对于错误的参数, 后果不可预测
	返回值: void
	*/
	{
		fa.clear();
		vis.clear();
		for(int i=1;i<=edge;++i)
		{
			int u=random(1,node),v=random(1,node);
			while(u==v||vis[u][v])
				u=random(1,node),v=random(1,node);
			vis[u][v]=1;
			Map[u].push_back(v);
		}
	}
}
using GRAPH_NAMESPACE::wuxiangtu;
using GRAPH_NAMESPACE::youxiangtu;

#endif