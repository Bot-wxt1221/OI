#include <iostream>
#include <cstdio>
int s[1005][1005];
int f[1005][1005];
using namespace std;
int main() {
//	freopen("numtri.in","r",stdin);
//	freopen("numtri.out","w",stdout);
	int r;
	cin>>r;
	for(int i=1; i<=r; i++) {
		for(int j=1; j<=i; j++) {
			cin>>s[i][j];
		}
	}
	for(int i=r; i; i--) {
		for(int j=i; j; j--) {
			f[i][j]=max(f[i+1][j],f[i+1][j+1])+s[i][j];
		}
	}
	cout<<f[1][1];
}
