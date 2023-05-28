#include <iostream>
#include <cstdio>
using namespace std;
int x[1005];
int y[1005];
bool c[1005];
int main(){
	freopen("kingdom.in","r",stdin);
	freopen("kingdom.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int temp;
			cin>>temp;
			if(temp==1){
				x[j]++;
			}else if(temp==0){
				y[j]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int temp;
		cin>>temp;
		if(temp==(x[i]>y[i])){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

