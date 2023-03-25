/*
删除最大的数字
错误代码：原因：前导0 
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
char a[255];
void del(int i){
	int size=strlen(a);
	for(int j=i+1;j<=size;j++){
		a[j-1]=a[j];
	}
}
int main(){
	freopen("delete.in","r",stdin);
	freopen("delete.out","w",stdout);
	int n,j,m;
	bool ans=0;
	cin>>a>>n;
	for(int i=1;i<=n;i++){
		bool can=1;
		for(int j=0;j<strlen(a);j++){
			if(a[j]>a[j+1]){
				del(j);
				can=0;
				break;
			}
		}
		if(can){
			del(strlen(a)-1);
		}
	}
	bool zero=1;
	for(int i=0;i<strlen(a);i++){
		if(zero&&a[i]=='0'){
			
		}else{
			zero=0;
			cout<<a[i];
		}
	}
	return 0;
}

