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
	cout << "����ͼ�ɹ���" << endl;
	int num;		         // ������
	char name[20];	// ��������
	char desc[1024];//��������
	ifstream VexR("Vex.txt"), EdgeR("Edge.txt") ;
	if (VexR.is_open()) {
		VexR >> m_Graph.m_nVexNum;
		
		for (int i = 0; i < m_Graph.m_nVexNum; i++) {
			VexR >> num >> name >> desc;
			Vex temp(num, name, desc);
			InsertVex(temp,i);
			
		}
	}
	int vex1, vex2;   //�ߵ�����������
	int weight;  	    //Ȩֵ
	if (EdgeR.is_open()) {
		while (!EdgeR.eof()) {
			EdgeR >> vex1 >> vex2 >> weight;
			Edge temp(vex1, vex2, weight);
			InsertEdge(temp);
		}
		
	}
	return;
}//��ȡ�ļ���������������ͼ��

void GetSpotInfo(void) {

	cout << "=====��ѯ������Ϣ=====" << endl;
	
	for (int i = 0; i < m_Graph.m_nVexNum; i++) {
		cout << m_Graph.m_aVexs[i].num << "-" << m_Graph.m_aVexs[i].name << endl;
	}
	cout << "��������Ҫ��ѯ�ľ�����:";
	int option;
	cin >> option;
	GetVex(option);

}// ��ѯָ��������Ϣ����ʾ�����ھ���ľ��롣

void TravelPath() {
	cout << "=====���ξ��㵼��=====" << endl;
	for (int i = 0; i < m_Graph.m_nVexNum; i++) {
		cout << m_Graph.m_aVexs[i].num << "-" << m_Graph.m_aVexs[i].name << endl;
	}
	cout << "��������ʼ����:";
	int option;
	cin >> option;
	cout << "����·��Ϊ:" << endl;
	PathList pList=new Path();
	DFSTraverse(option, pList);
}//��������������о����·��

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
	cout << begin << "(" << m_Graph.m_aVexs[begin].name << ")" << "-" << end << "(" << m_Graph.m_aVexs[end].name << ")" << "���·��Ϊ��" << dp[end] << endl;
	/*for (int i = 0; i < index; i++) {
		cout << route[i] << "(" << m_Graph.m_aVexs[route[i]].name <<")"<< "-" << route[i+1] << "(" << m_Graph.m_aVexs[route[i+1]].name <<")"<< "·��:" <<m_Graph.m_aAdjMatrix[route[i]][route[i+1]]<< endl;
		if (route[i+1] == end) {
			break;
		}
	}*/


}
void FindShortPath(void) {
	cout << "=====�������·��=====" << endl;
	for (int i = 0; i < m_Graph.m_nVexNum; i++) {
		cout << m_Graph.m_aVexs[i].num << "-" << m_Graph.m_aVexs[i].name << endl;
	}
	int nVexStart,nVexEnd,minRoute=0;
	/*Edge *aPath=new Edge();
	for (int i = 0; i < m_Graph.m_nVexNum; i++) {
		aPath[i] = *new Edge(-1, -1, 0);
	}*/
	
	cout << "��������ʼ���: ";
	cin >> nVexStart;
	cout << "�������յ���: " ;
	cin >> nVexEnd;
	FindShortPath(nVexStart, nVexEnd);
	/*cout << "���·��Ϊ:  " ;
	for (int i = 0; aPath[i].vex1 != -1; i++) {
		minRoute += aPath[i].weight;
		if (i != 0) cout << "->" << m_Graph.m_aVexs[aPath[i].vex2].name;
		else cout << m_Graph.m_aVexs[aPath[i].vex1].name <<"->" << m_Graph.m_aVexs[aPath[i].vex2].name;
	}
	cout << "��̾���Ϊ��" << minRoute;*/
}//ͨ������m_Graph()������ѯ�������������·���;���
void DesignPath(void) {
	cout << "=====�����·�滮=====" << endl;
	cout << "��������������֮�������·��" << endl;
	FindMinTree();

}//��·���

