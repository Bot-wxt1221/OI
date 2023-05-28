#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
class node {
	public:
		int a[105][105];
};
node ado(int n);
signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int m;
	scanf("%lld",&m);
	int n=(1<<m);
	node ans=ado(n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<ans.a[i][j]<<' ';
		}
		cout<<endl;
	}
}
node ado(int n){
	if(n==1){
		node temp;
		temp.a[1][1]=1;
		return temp;
	}
	node temp=ado(n>>1);
	int tn=(n>>1);
	node ans;
	for(int i=1;i<=tn;i++){
		for(int j=1;j<=tn;j++){
			ans.a[i][j]=temp.a[i][j];
		}
	}
	for(int i=tn+1;i<=tn*2;i++){
		for(int j=1;j<=tn;j++){
			ans.a[i][j]=temp.a[i-tn][j]+tn;
		}
	}
	for(int i=tn+1;i<=tn*2;i++){
		for(int j=1;j<=tn;j++){
			ans.a[j][i]=temp.a[j][i-tn]+tn;
		}
	}
	for(int i=tn+1;i<=tn*2;i++){
		for(int j=tn+1;j<=tn*2;j++){
			ans.a[i][j]=temp.a[i-tn][j-tn];
		}
	}
	return ans;
}
