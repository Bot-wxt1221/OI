#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	int a=0,x=1;
	char temp=getchar();
	while('0'>temp||temp>'9'){
		(temp=='-')?(x=-1):1;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		a=(a<<3)+(a<<1)+(temp^'0');
		temp=getchar();
	}
	return a*x;
}
int a[605];
int main(){
	int n=read();
	int w=read();
	for(int i=1;i<=n;i++){
		int temp=read();
		a[temp]++;
		int win=max(1,(i*w/100));
		bool ans=0;
		for(int j=600;j>=1;j--){
			win-=a[j];
			if(win<=0){
				printf("%d ",j);
				ans=1;
				break;
			}
		}
	}
}