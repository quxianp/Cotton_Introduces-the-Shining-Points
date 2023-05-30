#include <iostream>
#include <Windows.h>
#include <bits/stdc++.h>
#include <fstream>
#include <time.h>
//#include <cstring>
#include <conio.h>
#include <stdlib.h>
//#include "stdafx.h"
//#include <cstdlib>
#include <filesystem>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void white_print(string out) {
	cout << "\033[37;1m" << out << "\033[0m" ;
}

void Shining_Point(long long n) {
	for(int i=0; i<n; i++) white_print("."); //cout<<".";
	ofstream dataFile;
	dataFile.open("dataFile.ini", ofstream::app);
	dataFile<<" output:";
	for(int i=0; i<n; i++) dataFile<<".";
	dataFile<<endl<<endl;
	dataFile.close();
}

void green_print(string out,int a) {
	cout << "\033[32;1m" << out << "\033[0m";
	if(a==1) cout<<endl;
}

void information(char** argv) {
	time_t timep;
	struct tm *p;
	time(&timep);
	p=localtime(&timep);
	//cout<<"Source Code Address:https://github.com/quxianp/Cotton_Introduces-the-Shining-Points/"<<endl;
	green_print("Source Code Address:https://github.com/quxianp/Cotton_Introduces-the-Shining-Points/",1);
	//cout<<"Cotton_Introduces-the-Shining-Points vX.X"<<endl;
	green_print("Cotton_Introduces-the-Shining-Points v2.4",1);
	//cout<<"Current path:"<<endl;
	green_print("Current path:",0);
	cout<<"\033[32;1m"<<argv[0]<<"\033[0m"<<endl;
	//cout<<"Now Time:";
	green_print("Now Time:",0);
	//printf("%d/%d/%d %02d:%02d:%02d\n\n", 1900 + p->tm_year, 1+ p->tm_mon, p->tm_mday,p->tm_hour, p->tm_min, p->tm_sec);
	cout<<"\033[32;1m"<<1900 + p->tm_year<<"/"<<1+ p->tm_mon<<"/"<<p->tm_mday<<" "<<p->tm_hour<<":"<<p->tm_min<<":"<<p->tm_sec<<"\033[0m"<<endl<<endl;
	//cout<<"===== Start Running ====="<<endl<<endl;
	green_print("===== Start Running =====",1);
	cout<<endl;
}

bool isFileExists_ifstream(string& name) {
	ifstream f(name.c_str());
	return f.good();
}

void Decide() {
	string filename = "dataFile.ini";
	bool ret = isFileExists_ifstream(filename);
	if (!ret) fstream file("dataFile.ini", ios::out);
}

void text(long long n) {
	time_t timep;
	time(&timep);
	ofstream dataFile;
	dataFile.open("dataFile.ini", ofstream::app);
	//fstream file("dataFile.ini", ios::out);
	dataFile<<ctime(&timep)<<" "<<"input:"<<n<<endl;
	dataFile.close();
}

void PrintHistory() {
	ifstream ifs;
	ifs.open("dataFile.ini", ios::in);
	char c;
	ifs >> c;
	if (ifs.eof()) {
		cout << "==========================\n\n\n暂无相关记录！\n\n\n=========================="<<endl;
		ifs.close();
		return;
	} else {
		cout << "==========================" <<endl<<endl<<endl;
		ifstream inFile("dataFile.ini");
		string str;
		while (inFile.good()) {
			getline(inFile,str);
			cout<<str<<endl;
		}
		cout << "==========================" <<endl;
		//system("pause");
		/*cin.get();*/
	}
	ifs.close();
}

void CleanHistory() {
	ofstream fileout("dataFile.ini",ios::trunc);
	cout << "==========================\n\n\n清除成功！\n\n\n=========================="<<endl<<endl;
}

void History() {
	int ch;
	bool ks=false;
	cout<<"\033[35;1m*是否查看历史记录？*\033[0m"<<endl;
	cout<<"\033[35;1m*按下Enter键查看历史记录*\033[0m"<<endl;
	cout<<"\033[35;1m*按下BackSpace键清除历史记录*\033[0m"<<endl;
	cout<<"\033[35;1m*按下Tab键退出程序*\033[0m"<<endl;
	cout<<"\033[35;1m*按下ESC键进入主程序*\033[0m"<<endl<<endl;
	while (0!=1) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 27) break;
			if (ch == 9) exit(0);
			if(ks==false) {
				if (ch == 13) {
					PrintHistory();
					ks=true;
				}
			}
			if (ch == 8) CleanHistory();
		}
	}
}

int main(int argc, char** argv) {
	unsigned long long n;
	long double t;
	Decide();
	system("title Introduce_Your_Shining_Point_to_Your_Group-v2.4");
	//CreateDirectory(TEXT("Memories"),NULL);
	//system("color 0A"); //淡绿色
	information(argv);
	History();
	system("CLS"); //清屏
	//system("color 0B"); //浅绿色
	information(argv);
	//system("color 0F"); //亮白色
	while(1!=2) {
		//cout<<"你要向群友介绍多少个闪光点：";
		white_print("你要向群友介绍多少个闪光点（0≤个数≤9223372036854775807）：");
		cin>>t;
		if(t<0) white_print("输入错误 请输入正数\n\n"); //cout<<"输入错误，请输入正数！"<<endl<<endl;
		else if(t-(unsigned long long)t==0) break;
		//else cout<<"Wrong input,please try again and enter an integer!"<<endl<<endl;
		else white_print("输入错误 请输入整数\n\n"); //cout<<"输入错误，请输入整数！"<<endl<<endl;
	}
	n=(unsigned long long)t;
	text(n);
	//cout<<"闪光点：";
	white_print("闪光点：");
	Shining_Point(n);
	cout<<endl<<endl;

	system("pause");
	return 0;
}
