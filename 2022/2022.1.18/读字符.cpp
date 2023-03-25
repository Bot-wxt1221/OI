#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	char c;
	cout<<"enter a sentence:"<<endl;
	while(cin>>c){//cin忽略空格 
		cout<<c;
	}
	return 0;
}
//回车刷新缓冲区 ，未刷新后，放于缓冲区 
