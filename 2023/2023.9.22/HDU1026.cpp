#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
inline int read();
int map[16005];
int fir[16005];
int nxt[64005];
int v[64005];
bool get[64005];
int dpfr[16005];
int st[16005];
int head=1;
int now;
class node{
	public:
		int num,data;
		node(int xx,int yy){
			num=xx;
			data=yy;
			return ;
		}
};
bool operator < (node a,node b){
	return a.data>b.data;
}
int dp[16005];
std::priority_queue<node>de;
int xx[16005];
int yy[16005];
int getpos(int x,int y){
	return (x-1)*100+y;
}
void add(int x,int y){
	v[++now]=y;
	nxt[now]=fir[x];
	fir[x]=now;
	return ;
}
char temp[105];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n,m,TT=0;
	while(scanf("%d%d",&n,&m)!=EOF){
		now=0;
		for(int i=1;i<=n;i++){
            scanf("%s",temp+1);
			for(int j=1;j<=m;j++){
                xx[getpos(i,j)]=i;
                yy[getpos(i,j)]=j;
				if(temp[j]=='.'){
                    map[getpos(i,j)]=1;
                }else if(temp[j]=='X'){
                    map[getpos(i,j)]=0x3f3f3f3f;
                }else{
                    map[getpos(i,j)]=temp[j]-'0'+1;
                }
				fir[getpos(i,j)]=-1;
				dp[getpos(i,j)]=0x3f3f3f3f;
				get[getpos(i,j)]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i!=1){
					add(getpos(i,j),getpos(i-1,j));
				}
				if(j!=1){
					add(getpos(i,j),getpos(i,j-1));
				}
				if(i!=n){
					add(getpos(i,j),getpos(i+1,j));
				}
				if(j!=m){
					add(getpos(i,j),getpos(i,j+1));
				}
			}
		}
		dp[getpos(1,1)]=map[getpos(1,1)]-1;
		de.push(node(getpos(1,1),dp[getpos(1,1)]));
		while(de.size()>0){
			node te=de.top();
			de.pop();
			while(get[te.num]&&de.size()>0){
				te=de.top();
				de.pop();
			}
			if(get[te.num]){
				break;
			}
			get[te.num]=1;
			for(int i=fir[te.num];i!=-1;i=nxt[i]){
				if(dp[v[i]]>dp[te.num]+map[v[i]]){
					dp[v[i]]=dp[te.num]+map[v[i]];
                    dpfr[v[i]]=te.num;
					de.push(node(v[i],dp[v[i]]));
				}
			}
		}
        if(dp[getpos(n,m)]==0x3f3f3f3f){
            printf("God please help our poor hero.\nFINISH\n");
            continue;
        }
		printf("It takes %d seconds to reach the target position, let me show you the way.\n",dp[getpos(n,m)]);
        head=1;
        int fr=getpos(n,m);
        while(fr!=getpos(1,1)){
            st[head++]=fr;
            fr=dpfr[fr];
        }
        int time=1;
        st[head++]=getpos(1,1);
        for(int i=head-1;i>1;i--){
            printf("%ds:(%d,%d)->(%d,%d)\n",time++,xx[st[i]]-1,yy[st[i]]-1,xx[st[i-1]]-1,yy[st[i-1]]-1);
            for(int j=2;j<=map[st[i-1]];j++){
                printf("%ds:FIGHT AT (%d,%d)\n",time++,xx[st[i-1]]-1,yy[st[i-1]]-1);
            }
        }
        printf("FINISH\n");
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


