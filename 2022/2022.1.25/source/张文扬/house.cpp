#include <cstdio>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
int l,n,m;
const int maxn=5e4+10;
int a[maxn],bf[maxn];
int judge(int x){
	int k=0;
	bf[0]=0;
	for(int i=1;i<=n;++i){
		bf[i]=a[i];
		if(bf[i]-bf[i-1]<x){
			bf[i]=bf[i-1],k++;
		}
		if(k>m)return k;
	}
	return k;
}
/*
25 5 2
*/
int main(){
	freopen("house.in","r",stdin);
	freopen("house.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>l>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=0,a[++n]=l;
	int L=0,R=l;
	while(L+1<R){
		int mid=L+(R-L)/2;
		judge(mid)>m?R=mid:L=mid;
	}
//	cout<<L<<" "<<R<<endl;
	cout<<(judge(R)<=m?R:L)<<endl;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
