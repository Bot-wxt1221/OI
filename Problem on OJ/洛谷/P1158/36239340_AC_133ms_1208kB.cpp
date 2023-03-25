#include<bits/stdc++.h>
using namespace std;
inline int dist(int x1,int y1,int x2,int y2){return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);}
struct Jack{
	int l1,l2;
}f[110000];
inline bool cmp(const Jack &a,const Jack &b){return a.l1<b.l1;}
int main( ){
	int n,i,j,k,x1,x2,y1,y2,a,b;
	std::ios::sync_with_stdio(false);
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a>>b;
		f[i].l1=dist(x1,y1,a,b);
		f[i].l2=dist(x2,y2,a,b);
	}
	sort(f+1,f+n+1,cmp);
	int ans=f[n].l1,hei=-1;
	for(i=n-1;i>=1;i--){
		hei=max(hei,f[i+1].l2);
		ans=min(ans,hei+f[i].l1);
	}
	cout<<ans<<endl;
}