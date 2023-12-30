#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
namespace pro{
  std::queue<int>qu;
	int fir[40005];
	int nxt[80005];
	int v[80005];
	int w[80005];
	bool vised[80005];
	int now,k;
	bool df[20005];
	int siz[40005];
	int maxson[40005];
	int fd;
	int tot;
  int tree[20005];
  int lowbit(int x){
    return (x)&(-x);
  }
  void add(int x,int y){
    while(x<=20001){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
  int query(int x){
    int ans=0;
    while(x>0){
      ans+=tree[x];
      x-=lowbit(x);
    }
    return ans;
  }
	void heavy(int now,int fa) { 
		siz[now]=1;
		maxson[now]=0;
		for(int i=fir[now];i!=-1;i=nxt[i]){
			if(vised[v[i]]||v[i]==fa){
				continue;
			}
			heavy(v[i],now);
			maxson[now]=std::max(maxson[now],siz[v[i]]);
			siz[now]+=siz[v[i]];
		}
		maxson[now]=std::max(maxson[now],tot-maxson[now]);
		if(maxson[now]<maxson[fd]){
			fd=now;
		}
		return ;
	}
  int cnt;
  int dis[40005];
  int dd[40006];
  void ans(int now,int fa){
    dd[++cnt]=dis[now];
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(vised[v[i]]||v[i]==fa){
        continue;
      }
      dis[v[i]]=dis[now]+w[i];
      ans(v[i],now);
    }
    return ;
  }
  int anscnt=0;
	void dfs(int now,int fa){
		vised[now]=1;
    cnt=0;
    for(int i=fir[now];i!=-1;i=nxt[i]){
    	if(vised[v[i]]||fa==v[i]){
    		continue;
		}
      dis[v[i]]=w[i];
      cnt=0;
      ans(v[i],now);
      for(int j=1;j<=cnt;j++){
        if(dd[j]>k){
          continue;
        }
        anscnt+=query(k-dd[j]);
      }
      for(int j=1;j<=cnt;j++){
        if(dd[j]>k){
          continue;
        }
        add(dd[j],1);
        qu.push(dd[j]);
        anscnt++;
      }
    }
    while(qu.size()>0){
      add(qu.front(),-1);
      qu.pop();
    }
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa||vised[v[i]]){
        continue;
      }
      tot=siz[v[i]];
      fd=0;
      maxson[fd]=0x3f3f3f3f;
      heavy(v[i],now);
      heavy(fd,fd);
      dfs(fd,fd);
    }
    return ; 
	}
	void add(int x,int y,int z){
		v[++now]=y;
		w[now]=z;
		nxt[now]=fir[x];
		fir[x]=now;
		return ;
	}
	int main(){
		int n=read();
		for(int i=1;i<=n;i++){
			fir[i]=-1;
		}
		for(int i=1;i<n;i++){
			int u=read(),v;
			v=read();
			int w=read();
			add(u,v,w);
			add(v,u,w);
		}
		k=read();
		dfs(1,1);
		printf("%d",anscnt);
		return 0;
	}
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    
	return pro::main();
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

