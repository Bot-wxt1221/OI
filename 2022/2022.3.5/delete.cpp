/*
删除最大的数字
错误代码：原因：前导0 
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
bool out[2566];
char a[255];
char b[255];
int main(){
	freopen("delete.in","r",stdin);
	freopen("delete.out","w",stdout);
	int n;
	bool ans=0;
	cin>>a>>n;
	for(int n=0;n<strlen(a);n++){
		b[n]=-a[n];
	}
	sort(b,b+strlen(b));
	for(int i=0;i<n;i++){
		out[-b[i]]=1;
	}
	for(int i=0;i<strlen(a);i++){
		out[a[i]]?:cout<<a[i];
	}
	return 0;
}

