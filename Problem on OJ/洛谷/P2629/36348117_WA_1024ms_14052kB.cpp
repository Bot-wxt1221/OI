/*

*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;
deque<int>a;//求出待选的前缀和最小 
int b[2000005];
int qian[2000005];
signed main(){
	int n;
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		qian[i]=qian[i-1]+b[i];
	}
	for(int i=n+1;i<=2*n-1;i++){
		qian[i]=qian[i-1]+b[i-n];
	}
	for(int i=1;i<=2*n-1;i++){
		while(a.size()>0&&a.back()>=qian[i])	a.pop_back();
		a.push_back(i);
		if(i>=n){
			while(a.size()>0&&a.front()<=i-n)	a.pop_front();
			if(qian[a.front()]-qian[i-n]>=0)	ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
