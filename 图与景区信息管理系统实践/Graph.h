#pragma   once  
#ifndef Graph_h
//#define Graph_h
struct Vex
{
	int num;		         // ������
	char name[20];	// ��������
	char desc[1024];	// �������
	Vex(int num,char *name,char *desc) {
		this->num = num;
		strcpy(this->name, name);
		strcpy(this->desc , desc);
		
	}
	Vex(){}
};
struct Edge
{
	int vex1, vex2;   //�ߵ�����������
	int weight;  	    //Ȩֵ
	Edge(int vex1, int vex2, int weight) {
		this->vex1 = vex1;
		this->vex2 = vex2;
		this->weight = weight;
	}
	Edge() {

	}
};

struct Graph {
	int m_aAdjMatrix[20][20]; // �ڽӾ���
	Vex m_aVexs[20]; // ��������
	int m_nVexNum; // �������
};  // Graph�������ڴ洢��������ͼ
typedef struct Path
{
	int vexs[20];  //����һ��·��
	Path *next;  //��һ��·��
	Path() {
		memset(vexs, -1, sizeof(vexs));
	}
}*PathList;

const int MAX = 0x7fffff;
void Init(void);// ��ʼ��ͼ�ṹ��
void InsertVex(Vex sVex,int i);// ��������ӵ����������С�
void InsertEdge(Edge sEdge);// ���߱��浽�ڽӾ����С�
void GetVex(int nVex);// ��ѯָ��������Ϣ��
int FindEdge(int nVex);// ��ѯ��ָ�����������ıߡ�
int GetVexnum(void);// ��ȡ��ǰ������
void DFS(int nVex, bool bVisted[], int &nIndex, PathList &pList);
void DFSTraverse(int nVex, PathList &pList);
int FindShortPath(int nVexStart, int nVexEnd);
int FindMinTree();//����С������
#endif

