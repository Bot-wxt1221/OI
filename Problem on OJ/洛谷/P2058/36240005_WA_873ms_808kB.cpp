#include <iostream>
#include <cstdio>
using namespace std;
int ans=0;
bool have[1000000005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int n,m;
		cin>>n>>m;
		for(int j=1;j<=m;j++){
			cin>>n;
			if(!have[n])	ans++,have[n]=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
