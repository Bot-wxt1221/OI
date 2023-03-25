#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[3005][3005];
const int pre[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,i,j,ni,nj;
	cin>>n>>i>>j;
	int finish=1;
	a[1][1]=0;
	ni=1,nj=1;int toa=0,nowa=1,n2=n;
	while(finish<n*n){
		for(int is=1;is<n2;is++){
			ni+=pre[toa][0];
			nj+=pre[toa][1];
			a[ni][nj]=(++nowa);
			finish++;
		}
		toa++;
		if(toa==3){
			n2--;
		}
		toa%=4;
	}
	a[1][1]=1;
	cout<<a[i][j];
	return 0;
}
