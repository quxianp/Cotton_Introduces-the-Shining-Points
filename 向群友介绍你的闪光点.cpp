#include <iostream>
#include <Windows.h>
#include <bits/stdc++.h>
#include <fstream>
#include <time.h>
#include <string>
#include <conio.h>
#include <stdlib.h>
//#include "stdafx.h"
#include<cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long long n;
int ch;
double t;

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

void information() {
	time_t timep;
	struct tm *p;
	time(&timep);
	p=localtime(&timep);
	//cout<<"Source Code Address:https://github.com/quxianp/Cotton_Introduces-the-Shining-Points/"<<endl;
	green_print("Source Code Address:https://github.com/quxianp/Cotton_Introduces-the-Shining-Points/",1);
	//cout<<"Cotton_Introduces-the-Shining-Points v1.2"<<endl;
	green_print("Cotton_Introduces-the-Shining-Points v2.1",1);
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
		cout << "==========================\n\n\n������ؼ�¼��\n\n\n=========================="<<endl;
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

void History() {
	int ks=0;
	cout<<"\033[35;1m*�Ƿ�鿴��ʷ��¼��*\033[0m"<<endl<<"\033[35;1m*����Enter���鿴��ʷ��¼*\033[0m"<<endl<<"\033[35;1m*����ESC������������*\033[0m"<<endl<<endl<<endl;
	while (0!=1) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 27) break;
			if(ks==0) {
				if (ch == 13) {
					PrintHistory();
					ks=1;
				}
			}

		}
	}
}

int main(int argc, char** argv) {
	Decide();
	system("title Introduce_Your_Shining_Point_to_Your_Group-v2.1");
	//CreateDirectory(TEXT("Memories"),NULL);
	//system("color 0A"); //����ɫ
	information();
	History();
	system("CLS"); //����
	//system("color 0B"); //ǳ��ɫ
	information();
	//system("color 0F"); //����ɫ
	while(1!=2) {
		//cout<<"��Ҫ��Ⱥ�ѽ��ܶ��ٸ�����㣺";
		white_print("��Ҫ��Ⱥ�ѽ��ܶ��ٸ�����㣺");
		cin>>t;
		if(t<0) white_print("������� ����������\n\n"); //cout<<"�������������������"<<endl<<endl;
		else if(t-(int)t==0) break;
		//else cout<<"Wrong input,please try again and enter an integer!"<<endl<<endl;
		else white_print("������� ����������\n\n"); //cout<<"�������������������"<<endl<<endl;
	}
	n=(int)t;
	char a[n];
	text(n);
	//cout<<"����㣺";
	white_print("����㣺");
	Shining_Point(n);
	cout<<endl<<endl;
	system("pause");
	return 0;
}
