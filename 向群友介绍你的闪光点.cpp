#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long n;
void Shining_Point(long long n){
	for(int i=0;i<n;i++){
		cout<<".";
	}
}
void information(){
	cout<<"Source Code Address:https://github.com/quxianp/Cotton_Introduces-the-Shining-Points/"<<endl;
	cout<<"Cotton_Introduces-the-Shining-Points v1.0"<<endl;
	cout<<"===== Start Running ====="<<endl<<endl;
} 
int main(int argc, char** argv) {
	information();
	cout<<"你要向群友介绍多少个闪光点：";
	cin>>n;
	Shining_Point(n);
	cout<<endl;
	system("pause");
	return 0;
}
