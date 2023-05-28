#include <cstdio>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define int long long
int l,n,m;
const int maxn=5e4+10;
int a[maxn];
bool check(int x){
	int res=0,cnt=1;
	for(int i=1;i<=n;++i){
		if(res>x)return 0;
		if(res+a[i]>x){
			cnt++;
			res=a[i];
		}
		else res+=a[i];
	}
	return cnt<=m;
}
/*
10 4
10 1 9 2 8 3 7 4 6 5


5 3
4 2 4 5 1
*/
signed main(){
	freopen("divide_b.in","r",stdin);
	freopen("divide_b.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	int L=1,R=1e9;
	while(L<R){
		int mid=(L+R)/2;
		check(mid)?R=mid:L=mid+1;
	}
	cout<<L<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
