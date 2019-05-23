#include <iostream>
#include "Tourism.h";
#include "Graph.h"
struct Graph m_Graph;
using namespace std;

void show_menu() {
	cout << "=====景区信息管理系统=====" << endl;
	cout << "1.创建景区景点图" << endl;
	cout << "2.查询景点信息" << endl;
	cout << "3.旅游景点导肮" << endl;
	cout << "4.搜索最短路径" << endl;
	cout << "5.铺设电路规划" << endl;
	cout << "0.退出" << endl;
	cout << "请输入操作编号（0~5）:";

}
int main() {
	char option[20];
	while (true) {
		system("pause");
		system("cls");
		show_menu();
		cin >> option;
		if (strcmp(option, "1") == 0) {
			CreateGraph();
		}
		else if (strcmp(option, "2") == 0) {			
			GetSpotInfo();
		}
		else if (strcmp(option, "3") == 0) {
			TravelPath();
		}
		else if (strcmp(option, "4") == 0) {
			FindShortPath();
		}
		else if (strcmp(option, "5") == 0) {
			DesignPath();
		}
		else if (strcmp(option, "0") == 0) {
			break;
		}
	}
	return 0;
}