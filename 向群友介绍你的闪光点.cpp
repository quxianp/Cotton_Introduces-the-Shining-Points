#include <iostream>
#include <Windows.h>
#include <bits/stdc++.h>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long long n;
double t;

void Shining_Point(long long n){
	for(int i=0;i<n;i++) cout<<".";
	ofstream dataFile;
	dataFile.open("dataFile.txt", ofstream::app);
	dataFile<<" output:";
	for(int i=0;i<n;i++) dataFile<<".";
	dataFile<<endl<<endl;
	dataFile.close();
}

void information(){
	time_t timep;
	struct tm *p;
	time(&timep);
	p=localtime(&timep);
	cout<<"Source Code Address:https://github.com/quxianp/Cotton_Introduces-the-Shining-Points/"<<endl;
	cout<<"Cotton_Introduces-the-Shining-Points v1.2"<<endl;
	cout<<"Now Time:";
	printf("%d/%d/%d %02d:%02d:%02d\n\n", 1900 + p->tm_year, 1+ p->tm_mon, p->tm_mday,p->tm_hour, p->tm_min, p->tm_sec); 
	cout<<"===== Start Running ====="<<endl<<endl;
} 

bool isFileExists_ifstream(string& name) {
    ifstream f(name.c_str());
    return f.good();
}

void Decide(){
	string filename = "dataFile.txt";
    bool ret = isFileExists_ifstream(filename);
    if (!ret) fstream file("dataFile.txt", ios::out);
}

void text(long long n){
	Decide();
	time_t timep;
	time(&timep);
	ofstream dataFile;
	dataFile.open("dataFile.txt", ofstream::app);
	//fstream file("dataFile.txt", ios::out);
	dataFile<<ctime(&timep)<<" "<<"input:"<<n<<endl;
	dataFile.close();
}

int main(int argc, char** argv) {
	//CreateDirectory(TEXT("Memories"),NULL);
	information();
	while(1!=2){
		cout<<"你要向群友介绍多少个闪光点：";
		cin>>t;
		if(t<0) cout<<"输入错误，请输入正数！"<<endl<<endl;
		else if(t-(int)t==0) break;
		//else cout<<"Wrong input,please try again and enter an integer!"<<endl<<endl; 
		else cout<<"输入错误，请输入整数！"<<endl<<endl;
		
	}
	n=(int)t;
	char a[n];
	text(n);
	cout<<"闪光点：";
	Shining_Point(n);
	cout<<endl<<endl;
	system("pause");
	return 0;
}
