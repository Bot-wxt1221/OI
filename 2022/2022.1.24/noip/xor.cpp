#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
bool vised[20];
long long ans[20];
int a[20];
unsigned long long n,ansss=-1ULL;
void dfs(int step);
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<ansss;
	return 0;
}
void dfs(int step){
	if(step==n){
		unsigned long long ansa=0;
		for(int i=1;i<=n;i++){
			ansa+=ans[i];
		}
		ansss=min(ansss,ansa);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(ans[i]){
		ans[i]=ans[i]^a[step];
		dfs(step+1);
		ans[i]=ans[i]^a[step];
		}else{
			ans[i]=a[step];
			dfs(step+1);
			ans[i]=0;
		}
	}
	return ;
}
