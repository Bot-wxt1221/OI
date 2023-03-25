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
int ans[100000];
int main(){
	int n=read();
	if(n&1==1){
		printf("-1");
	}else{
		int temp=0;
		int ansa=0;
		while(n>0){
			temp++;
			if(n&1==1){
				ans[ansa++]=temp-1;
			}
			n=n/2;
		}
		for(int i=ansa-1;i>=0;i--){
			printf("%d ",(1<<ans[i]));
		}
	}
}