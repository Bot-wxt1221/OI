#include <iostream>
#include <cstdio>
#include <algorithm> 
inline int read();
class node{
  public:
    int x,y;
    bool ana;
    int t1=-1,t2=-1,t3=-1,t4=-1;
}pos[2500005];
bool cmp(node a,node b){
  if(a.x!=b.x){
    return a.x<b.x;
  }
  if(a.y!=b.y){
    return a.y<b.y;
  }
  return a.ana>b.ana;
}
int tree[10000005];
int lowbit(int x){
  return x&(-x);
}
int query(int now){
  int ans=0;
  while(now>0){
    ans+=tree[now];
    now-=lowbit(now);
  }
  return ans;
}
void add(int now,int op){
  while(now<=10000001){
    tree[now]+=op;
    now+=lowbit(now);
  }
  return ;
}
int ask[2500005];
int l1[500005];
int r1[500005];
int l2[500005];
int r2[500005];
int t1[500005];
int t2[500005];
int t3[500005];
int t4[500005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),m;
  m=read();
  for(int i=1;i<=n;i++){
    pos[i].x=read();
    pos[i].y=read()+1;
    pos[i].ana=1;
  }
  for(int i=1;i<=m;i++){
    l1[i]=read();
    r1[i]=read();
    pos[++n].x=l1[i]-1;
    pos[n].y=r1[i];
    pos[n].ana=0;
    pos[n].t1=i;
    l2[i]=read();
    r2[i]=read();
    pos[++n].x=l2[i];
    pos[n].y=r2[i]+1;
    pos[n].ana=0;
    pos[n].t2=i;
    pos[++n].x=l1[i]-1;
    pos[n].y=r2[i]+1;
    pos[n].ana=0;
    pos[n].t3=i;
    pos[++n].x=l2[i];
    pos[n].y=r1[i];
    pos[n].ana=0;
    pos[n].t4=i;
  }
  std::sort(pos+1,pos+n+1,cmp);
  for(int i=1;i<=n;i++){
  	if(pos[i].y==0){
  	  ask[i]=0;
  	  continue;
	}
    add(pos[i].y,pos[i].ana);
    ask[i]=query(pos[i].y);
    if(pos[i].t1!=-1){
    	t1[pos[i].t1]=i;
	}
	if(pos[i].t2!=-1){
    	t2[pos[i].t2]=i;
	}
	if(pos[i].t3!=-1){
    	t3[pos[i].t3]=i;
	}
	if(pos[i].t4!=-1){
    	t4[pos[i].t4]=i;
	}
  }
  for(int i=1;i<=m;i++){
    printf("%d\n",ask[t2[i]]-ask[t3[i]]-ask[t4[i]]+ask[t1[i]]);
  }
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