#include <iostream>
#include<fstream>
#include <cstdio>
#include <algorithm>
#include "Graph.h"
#include "Tourism.h"
using namespace std;
extern struct Graph m_Graph;

void CreateGraph(void) {
	Init();
	cout << "创建图成功！" << endl;
	int num;		         // 景点编号
	char name[20];	// 景点名字
	char desc[1024];//景点描述
	ifstream VexR("Vex.txt"), EdgeR("Edge.txt") ;
	if (VexR.is_open()) {
		VexR >> m_Graph.m_nVexNum;
		
		for (int i = 0; i < m_Graph.m_nVexNum; i++) {
			VexR >> num >> name >> desc;
			Vex temp(num, name, desc);
			InsertVex(temp,i);
			
		}
	}
	int vex1, vex2;   //边的两个个顶点
	int weight;  	    //权值
	if (EdgeR.is_open()) {
		while (!EdgeR.eof()) {
			EdgeR >> vex1 >> vex2 >> weight;
			Edge temp(vex1, vex2, weight);
			InsertEdge(temp);
		}
		
	}
	return;
}//读取文件，创建景区景点图。

void GetSpotInfo(void) {

	cout << "=====查询景点信息=====" << endl;
	
	for (int i = 0; i < m_Graph.m_nVexNum; i++) {
		cout << m_Graph.m_aVexs[i].num << "-" << m_Graph.m_aVexs[i].name << endl;
	}
	cout << "请输入想要查询的景点编号:";
	int option;
	cin >> option;
	GetVex(option);

}// 查询指定景点信息，显示到相邻景点的距离。

void TravelPath() {
	cout << "=====旅游景点导航=====" << endl;
	for (int i = 0; i < m_Graph.m_nVexNum; i++) {
		cout << m_Graph.m_aVexs[i].num << "-" << m_Graph.m_aVexs[i].name << endl;
	}
	cout << "请输入起始点编号:";
	int option;
	cin >> option;
	cout << "导航路线为:" << endl;
	PathList pList=new Path();
	DFSTraverse(option, pList);
}//输入起点游览所有景点的路线

void MinRoute(int begin, int end) {
	int dp[20];
	int route[20];
	route[0] = begin;
	int index = 1;

	memset(route, -1, sizeof(route));
	int Vexnum = GetVexnum();
	for (int i = 0; i < Vexnum; i++) dp[i] = m_Graph.m_aAdjMatrix[begin][i];
	for (int i = 0; i < Vexnum; i++) {
		for (int j = 0; j < Vexnum; j++) {
			dp[j] = min(dp[j], dp[i] + m_Graph.m_aAdjMatrix[i][j]);
		}
	}
	for (int i = Vexnum - 1; i >= 0; i++) {
		if (dp[end] == dp[i] + m_Graph.m_aAdjMatrix[i][end])
			route[index++] = i;
	}
	cout << begin << "(" << m_Graph.m_aVexs[begin].name << ")" << "-" << end << "(" << m_Graph.m_aVexs[end].name << ")" << "最短路径为：" << dp[end] << endl;
	/*for (int i = 0; i < index; i++) {
		cout << route[i] << "(" << m_Graph.m_aVexs[route[i]].name <<")"<< "-" << route[i+1] << "(" << m_Graph.m_aVexs[route[i+1]].name <<")"<< "路长:" <<m_Graph.m_aAdjMatrix[route[i]][route[i+1]]<< endl;
		if (route[i+1] == end) {
			break;
		}
	}*/


}
void FindShortPath(void) {
	cout << "=====搜索最短路径=====" << endl;
	for (int i = 0; i < m_Graph.m_nVexNum; i++) {
		cout << m_Graph.m_aVexs[i].num << "-" << m_Graph.m_aVexs[i].name << endl;
	}
	int nVexStart,nVexEnd,minRoute=0;
	/*Edge *aPath=new Edge();
	for (int i = 0; i < m_Graph.m_nVexNum; i++) {
		aPath[i] = *new Edge(-1, -1, 0);
	}*/
	
	cout << "请输入起始编号: ";
	cin >> nVexStart;
	cout << "请输入终点编号: " ;
	cin >> nVexEnd;
	FindShortPath(nVexStart, nVexEnd);
	/*cout << "最短路线为:  " ;
	for (int i = 0; aPath[i].vex1 != -1; i++) {
		minRoute += aPath[i].weight;
		if (i != 0) cout << "->" << m_Graph.m_aVexs[aPath[i].vex2].name;
		else cout << m_Graph.m_aVexs[aPath[i].vex1].name <<"->" << m_Graph.m_aVexs[aPath[i].vex2].name;
	}
	cout << "最短距离为：" << minRoute;*/
}//通过调用m_Graph()函数查询两个景点间的最短路径和距离
void DesignPath(void) {
	cout << "=====铺设电路规划=====" << endl;
	cout << "在以下两个景点之间铺设电路：" << endl;
	FindMinTree();

}//电路设计

