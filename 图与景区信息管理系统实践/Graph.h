#pragma   once  
#ifndef Graph_h
//#define Graph_h
struct Vex
{
	int num;		         // 景点编号
	char name[20];	// 景点名字
	char desc[1024];	// 景点介绍
	Vex(int num,char *name,char *desc) {
		this->num = num;
		strcpy(this->name, name);
		strcpy(this->desc , desc);
		
	}
	Vex(){}
};
struct Edge
{
	int vex1, vex2;   //边的两个个顶点
	int weight;  	    //权值
	Edge(int vex1, int vex2, int weight) {
		this->vex1 = vex1;
		this->vex2 = vex2;
		this->weight = weight;
	}
	Edge() {

	}
};

struct Graph {
	int m_aAdjMatrix[20][20]; // 邻接矩阵
	Vex m_aVexs[20]; // 顶点数组
	int m_nVexNum; // 顶点个数
};  // Graph对象，用于存储景区景点图
typedef struct Path
{
	int vexs[20];  //保存一条路径
	Path *next;  //下一条路径
	Path() {
		memset(vexs, -1, sizeof(vexs));
	}
}*PathList;

const int MAX = 0x7fffff;
void Init(void);// 初始化图结构。
void InsertVex(Vex sVex,int i);// 将顶点添加到顶点数组中。
void InsertEdge(Edge sEdge);// 将边保存到邻接矩阵中。
void GetVex(int nVex);// 查询指定顶点信息。
int FindEdge(int nVex);// 查询与指定顶点相连的边。
int GetVexnum(void);// 获取当前顶点数
void DFS(int nVex, bool bVisted[], int &nIndex, PathList &pList);
void DFSTraverse(int nVex, PathList &pList);
int FindShortPath(int nVexStart, int nVexEnd);
int FindMinTree();//求最小生成树
#endif

