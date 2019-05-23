#pragma   once  
#ifndef Tourism_h
#define Tourism_h
void CreateGraph(void);//读取文件，创建景区景点图。
void GetSpotInfo(void);//查询指定景点信息，显示到相邻景点的距离。
void MinRoute(int begin, int end);//最短路求解
void TravelPath();//输出旅游导航路径
void FindShortPath(void);//查询最短路径
void DesignPath(void);//电路线路设计
#endif
