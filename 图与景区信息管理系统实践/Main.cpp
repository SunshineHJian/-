#include <iostream>
#include "Tourism.h";
#include "Graph.h"
struct Graph m_Graph;
using namespace std;

void show_menu() {
	cout << "=====������Ϣ����ϵͳ=====" << endl;
	cout << "1.������������ͼ" << endl;
	cout << "2.��ѯ������Ϣ" << endl;
	cout << "3.���ξ��㵼��" << endl;
	cout << "4.�������·��" << endl;
	cout << "5.�����·�滮" << endl;
	cout << "0.�˳�" << endl;
	cout << "�����������ţ�0~5��:";

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