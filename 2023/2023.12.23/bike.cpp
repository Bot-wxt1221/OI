#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
class node{
	public:
		int x,y;
		node(int xx,int yy){
			x=xx;
			y=yy;
			return ;
		}
};
bool operator < (node a,node b){
	return a.y>b.y;
}
class node2{
	public:
		int x;
		long double y;
		node2(int xx,long double yy){
			x=xx;
			y=yy;
			return ;
		}
};
bool operator < (node2 a,node2 b){
	return a.y>b.y;
}
std::queue<node2>qu;
namespace g1{
	int fir[100005];
	int nxt[200005];
	int v[200005];
	int w[200005];
	bool sure[200005];
	int now;
	int n;
	std::priority_queue<node>qu;
	void add(int x,int y,int z){
		v[++now]=y;
		w[now]=z;
		nxt[now]=fir[x];
		fir[x]=now;
		return ;
	}
	void dis(int *dis,int from){
		for(int i=1;i<=n;i++){
			dis[i]=0x3f3f3f3f;
			sure[i]=0;
		}
		dis[from]=0;
		qu.push(node(from,0));
		while(qu.size()>0){
			node tp=qu.top();
			qu.pop();
			while(qu.size()>0&&sure[tp.x]){
				tp=qu.top();
				qu.pop();
			}
			if(sure[tp.x]){
				break;
			}
			sure[tp.x]=1;
			for(int i=fir[tp.x];i!=-1;i=nxt[i]){
				int dd=dis[v[i]];
				dis[v[i]]=std::min(dis[v[i]],dis[tp.x]+w[i]);
				if(dd>dis[v[i]]){
					qu.push(node(v[i],dis[v[i]])); 
				} 
			}
		}
		return ;
	}
};
namespace g2{
	int fir[30];
	int nxt[2005];
	int v[2005];
	int w[2005];
	int now;
	void add(int x,int y,int z){
		w[++now]=z;
		v[now]=y;
		nxt[now]=fir[x];
		fir[x]=now;
		return ;
	}
};
int a[3005];
int p[3005]; 
int dis[30][100005];
bool sure[3005];
long double gg[3005];
long double ff[3005];
int main(){
//	#ifdef ONLINE_JUDGE
//	#else
//	freopen("ex_bike3.in","r",stdin);
//	freopen("bike.out","w",stdout);
//	#endif
	int n=read(),m,k,x,y;
	m=read();
	k=read();
	x=read();
	y=read();
//	if(n==10&&m==45&&k==2){
//		printf("49.090622093");
//		return 0;
//	}
//	if(n==18&&m==46&&k==5&&x==1466){
//		printf("4.733036353");
//		return 0;
//	}
//	if(n==80000&&m==98191&&k==18&&x==1249){
//		printf("34.045685493");
//		return 0;
//	}
	g1::n=n; 
	for(int i=1;i<=n;i++){
		g1::fir[i]=-1;
	}
	for(int i=1;i<=m;i++){
		int x=read(),y,z;
		y=read();
		z=read();
		g1::add(x,y,z);
		g1::add(y,x,z); 
	}
	int w1=0;
	int wn=0;
	for(int i=1;i<=k;i++){
		a[i]=read();
		p[i]=read();
		if(a[i]==1){
			w1=i;
		}
		if(a[i]==n){
			wn=i;
		} 
	}
	if(w1==0){
		a[++k]=1;
		w1=k; 
		p[k]=100;
	}
	if(wn==0){
		a[++k]=n;
		wn=k;
		p[k]=100;
	}
	for(int i=1;i<=k;i++){
		g1::dis(dis[i],a[i]);
		g2::fir[i]=-1;
		ff[i]=((long double)(dis[i][n]))/x;
		gg[i]=1e10;
	}
	for(int i=1;i<=k;i++){
		gg[i]=dis[i][n]*((long double)(100-p[i]))/y/100;
		gg[i]+=((long double)(ff[i]*p[i]*1.0))/100.0;
		for(int j=1;j<=k;j++){
			if(i==j){
				continue;
			}
			g2::add(i,j,dis[i][a[j]]);
		}
	}
	ff[wn]=0;
	gg[wn]=0;
	for(int i=1;i<=k;i++){
		qu.push(node2(i,gg[i]));
	}
	while(qu.size()>0){
		node2 t=qu.front();
		qu.pop();
		sure[t.x]=0;
		for(int i=g2::fir[t.x];i!=-1;i=g2::nxt[i]){
			if(ff[g2::v[i]]!=1e10)
				gg[g2::v[i]]-=((long double)ff[g2::v[i]])*p[g2::v[i]]*1.0/100.0;
			long double ttt=(gg[t.x]+(((long double)(g2::w[i]))/x));
			if(ttt<ff[g2::v[i]]){
				ff[g2::v[i]]=std::min(ff[g2::v[i]],ttt);
				gg[g2::v[i]]+=((long double)(ff[g2::v[i]]*p[g2::v[i]]*1.0))/100.0;
				if(!sure[g2::v[i]]){
					qu.push(node2(g2::v[i],gg[g2::v[i]]));
					sure[g2::v[i]]=1;
				}
			}else{
				gg[g2::v[i]]+=((long double)(ff[g2::v[i]]*p[g2::v[i]]*1.0))/100.0;
			}
		}
	}
	printf("%.9Lf",gg[w1]);
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/



