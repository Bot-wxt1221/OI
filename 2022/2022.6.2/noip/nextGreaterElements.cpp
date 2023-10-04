#include <iostream>
#include <cstdio>
using namespace std;
int a[20005];
int ans[20005];
int St[20005];
int top=0;
int main(){
	freopen("nextGreaterElements.in","r",stdin);
	freopen("nextGreaterElements.out","w",stdout);
	int n=0;
	while(scanf("%d",&a[++n])==1);
	n--;
	for(int i=1;i<=n;i++){
		a[i+n]=a[i];
	}
	for(int i=2*n;i>=1;i--){
		while(top>0&&St[top-1]<=a[i])	top--;
		if(top!=0)
			ans[i]=St[top-1];
		else
			ans[i]=-1;
		St[top++]=a[i];
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


