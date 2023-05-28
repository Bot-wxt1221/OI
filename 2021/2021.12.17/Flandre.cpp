#include <iostream>
#include <cstdio>
#define mod 1000000007
using namespace std;
int n,k;
unsigned long long ans,ans2;
void dfs(int step,int sheng);
int main(){
    freopen("Flandre.in","r",stdin);
    freopen("Flandre.out","w",stdout);
	cin>>n>>k;
	dfs(0,0);
	ans=ans%mod;
	ans2=ans2%mod;
	cout<<ans<<"/"<<ans2;
    return 0;
}
void dfs(int step,int sheng){
	if(step==n){
		if(sheng==k){
			ans++;
		}
		ans2++;
		ans=ans%mod;
		ans2=ans2%mod;
		return;
	}
	dfs(step+1,sheng);
	dfs(step+1,sheng+1);
	dfs(step+1,sheng+1);
	return; 
}
