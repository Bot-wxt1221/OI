#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
class node{
	public:
		int v,w;
		double vw;
}can[105];
inline bool cmp(node a,node b){
	return a.vw>b.vw;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,w;
	cin>>n>>w;
	for(int i=1;i<=n;i++){
		cin>>can[i].v>>can[i].w;
		can[i].vw=double(can[i].v)/can[i].w;
	}
	sort(can+1,can+n+1,cmp);
	double ans=0;
	for(int i=1;i<=n;i++){
		if(w>=can[i].w){
			w-=can[i].w;
			ans+=can[i].v;
		}else{
			ans+=can[i].vw*w;
			break;
		}
	}
	printf("%.1lf",ans);
	return 0;
}
/*
i:
4 15
100 4
412 8
266 7
591 2
o:
1193.0
*/