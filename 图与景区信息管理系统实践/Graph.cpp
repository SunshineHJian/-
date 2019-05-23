#include <iostream>
#include <bits/stdc++.h>
#include "Graph.h"
#include "Tourism.h"
extern struct Graph m_Graph;
using namespace std;

void Init(void) {
	m_Graph.m_nVexNum = 0;
	for (int i = 0; i < 20; i++) {
		strcpy(m_Graph.m_aVexs[i].name, "");
		strcpy(m_Graph.m_aVexs[i].desc, "");
		m_Graph.m_aVexs[i].num = -1;
		for (int j = 0; j < 20; j++) {
			if (i == j) m_Graph.m_aAdjMatrix[i][j] = 0;
			else m_Graph.m_aAdjMatrix[i][j] = MAX;
		}
		
	}

}// 初始化图结构。
void InsertVex(Vex sVex,int i) {
	m_Graph.m_aVexs[i].num =sVex.num;
	strcpy(m_Graph.m_aVexs[i].name, sVex.name);
	strcpy(m_Graph.m_aVexs[i].desc, sVex.desc);

}// 将顶点添加到顶点数组中。
void InsertEdge(Edge sEdge) {
	m_Graph.m_aAdjMatrix[sEdge.vex1][sEdge.vex2] = sEdge.weight;
	m_Graph.m_aAdjMatrix[sEdge.vex2][sEdge.vex1] = sEdge.weight;
}// 将边保存到邻接矩阵中。
void GetVex(int nVex) {
	
	cout << m_Graph.m_aVexs[nVex].name << endl;
	cout << m_Graph.m_aVexs[nVex].desc << endl;
	cout << "-----周边景区-----" << endl;
	FindEdge(nVex);

}// 查询指定顶点信息。
int FindEdge(int nVex) {
	
	for (int i = 0; i < m_Graph.m_nVexNum; i++) {
		if (i != m_Graph.m_aVexs[nVex].num&&m_Graph.m_aAdjMatrix[m_Graph.m_aVexs[nVex].num][i] != MAX) {
			cout << m_Graph.m_aVexs[nVex].name << "-" << m_Graph.m_aVexs[i].name << " " << m_Graph.m_aAdjMatrix[m_Graph.m_aVexs[nVex].num][i] << endl;
		}
	}
	return 0;

}// 查询与指定顶点相连的边。
int GetVexnum(void) {

	return m_Graph.m_nVexNum;
}// 获取当前顶点数
void DFS(int nVex, bool bVisted[], int &nIndex, PathList &pList) {
	bVisted[nVex] = false;
	if (nIndex == m_Graph.m_nVexNum - 1) {
		pList->next = new Path();
		for (int i = 0; i < m_Graph.m_nVexNum - 1; i++) {
			pList->next->vexs[i] = pList->vexs[i];
		}
		pList = pList->next;
		pList->next = NULL;
		bVisted[nVex] = true;
		return;
	}
	for (int i = 0; i < m_Graph.m_nVexNum; i++) {
		if (i == nVex||!bVisted[i]) continue;
		if (m_Graph.m_aAdjMatrix[nVex][i] != MAX) {
			pList->vexs[nIndex++] = i;
			DFS(i, bVisted, nIndex, pList);
			nIndex--;
		}
	}
	bVisted[nVex] = true;

}
void DFSTraverse(int nVex, PathList &pList) {
	bool bVisted[20];
	memset(bVisted, true, sizeof(bVisted));
	int nIndex = 0, countn = 0;
	PathList temp = pList;
	pList->next = NULL;
	DFS(nVex, bVisted, nIndex, temp);
	while (pList != NULL) {
		cout << "路线" << ++countn << ": "<<m_Graph.m_aVexs[nVex].name;
		for (int i = 0; pList->vexs[i] != -1; i++) {
			cout << " -> " << m_Graph.m_aVexs[pList->vexs[i]].name;
		}
		cout << endl;
		pList = pList->next;
	}
}
int FindShortPath(int nVexStart, int nVexEnd) {
	int dp[20][20];
	int index = 0,flag=0;
	//aPath[index].vex1 = nVexStart;
	//aPath[index].vex2 = nVexEnd;
	//aPath[index].weight = m_Graph.m_aAdjMatrix[nVexStart][nVexEnd];
	int route[20];
	memset(route, -1, sizeof(-1));
	int Vexnum = GetVexnum();
	for (int i = 0; i < Vexnum; i++) dp[0][i] = m_Graph.m_aAdjMatrix[nVexStart][i];
	for (int i = 0; i < Vexnum; i++) {
		if (i == nVexStart) {
			for (int j = 0; j < Vexnum; j++) {
				dp[i + 1][j] = dp[i][j];
			}
			continue;
		}
		for (int j = 0; j < Vexnum; j++) {
			dp[i+1][j] = min(dp[i][j], dp[i][i] + m_Graph.m_aAdjMatrix[i][j]);
		}
	}

	int x = Vexnum ;
	int y = nVexEnd;
	route[0] = nVexEnd;
	while (x) {
		if (x == nVexStart) {
			x--;
			continue;
		}
		for (int i = 0; i < Vexnum; i++) {
			
			if (dp[x][y] == dp[x - 1][i] + m_Graph.m_aAdjMatrix[i][y]) {
				route[++index] = i;
				y = i;
				if (i == nVexStart) {
					x = 1;
					break;
				}
			}			
		}
		x--;
	}
	int minRoute = 0;
	cout << "最短路线为:  "<<m_Graph.m_aVexs[nVexStart].name;
	
	for (int i = index-1; i>=0; i--) {
		minRoute += m_Graph.m_aAdjMatrix[route[i + 1]][route[i]];
		cout << "->" << m_Graph.m_aVexs[route[i]].name;
		if (route[i] == nVexEnd) break;
	}
	cout << endl << "最短距离为：" << minRoute << endl;
	return minRoute;
}//通过Dijkstra算法求得v1到v2的最短路径

struct neigbor_egde {
	int weight;
	int index;
	int parent;
	neigbor_egde(){}
	neigbor_egde(int weight,int index,int parent):weight(weight),index(index),parent(parent){}
	
	
};
const bool operator< (neigbor_egde const temp1, neigbor_egde const temp2) {
	return temp1.weight > temp2.weight;
}
int FindMinTree() {
	priority_queue<neigbor_egde> que;
	set <int> V;
	V.insert(0);
	int index = 0,flag=1;
	int num = GetVexnum();
	int sumRoute = 0;
	while (flag != num) {
		for (int i = 0; i < num; i++) {
			if (m_Graph.m_aAdjMatrix[index][i] != MAX && i != index) {
				neigbor_egde temp(m_Graph.m_aAdjMatrix[index][i], i, index);
				que.push(temp);
			}
		}
		while (true) {
			neigbor_egde temp = que.top();
			que.pop();
			if (V.count(temp.index) == 0) {
				V.insert(temp.index);
				cout << m_Graph.m_aVexs[temp.parent].name << " -> " << m_Graph.m_aVexs[temp.index].name<<"  "<<temp.weight<<"米"<<endl;
				index = temp.index;
				flag++;
				sumRoute += temp.weight;
				break;
			}
		}
	}
	cout << "铺设的总长度为："<<sumRoute <<"米"<< endl;
	return 0;
}