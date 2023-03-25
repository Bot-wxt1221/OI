#include <iostream>
#include <cstdio>
using namespace std;
long long a[105][105];
long long b[105][105];
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m,p,n;
	cin>>m>>p>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=p;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=p;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int temp=0;
			for(int k=1;k<=p;k++){
				temp+=a[i][k]*b[k][j];
			}
			cout<<temp<<' ';
		}
		cout<<endl;
	}
	return 0;
}
