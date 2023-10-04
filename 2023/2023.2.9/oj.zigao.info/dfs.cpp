#include <iostream>
#include <cstdio>
#include <stack>
inline int read();
int map[105][105];
int out[10005];
int out2[1005];
bool vised[10005];
class node{
    public:
        int now;
        int v;
        node(int nn,int vv){
            now=nn;
            v=vv;
            return ;
        }
};
std::stack<node>d;
int now;

int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("dfs.in","r",stdin);
	freopen("dfs.out","w",stdout);
	#endif
    int n=read(),m;
    // m=read();
    for(int i=1;i<=n;i++){
        int id=read();
        int k=read();
        for(int i=1;i<=k;i++){
            map[id][read()]=1;
        }
    }
    int anow=0;
    for(int i=1;i<=n;i++){
        if(vised[i]){
            continue;
        }
        d.push(node(i,0));
        while(d.size()>0){
            node now=d.top();
            d.pop();
            if(now.v==0){
                if(vised[now.now]){
                    continue;
                }
                vised[now.now]=1;
                out[now.now]=++anow;
                bool yes=0;
                for(int i=1;i<=n;i++){
                    if(vised[i]==0&&map[now.now][i]){
                        d.push(node(now.now,i));
                        d.push(node(i,0));
                        yes=1;
                        break;
                    }
                }
                if(!yes){
                    out2[now.now]=++anow;
                }
            }else{
                bool yes=0;
                for(int i=now.v+1;i<=n;i++){
                    if(vised[i]==0&&map[now.now][i]){
                        d.push(node(now.now,i));
                        d.push(node(i,0));
                        yes=1;
                        break;
                    }
                }
                if(!yes){
                    out2[now.now]=++anow;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d %d %d\n",i,out[i],out2[i]);
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


