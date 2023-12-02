#include <iostream>
#include <cstdio>
inline int read();
int c[500005];
int l[500005];
int r[500005];
int ans[500005];
bool exist[500005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read(),m,q;
    m=read();
    q=read();
    for(int i=1;i<=n;i++){
        c[i]=read();
    }
    for(int i=1;i<=m;i++){
        l[i]=read();
        r[i]=read();
        for(int j=1;j<=n;j++){
            exist[j]=0;
        }
        for(int j=l[i];j<=r[i];j++){
            if(exist[c[j]]){
                ans[i]=-1;
                break;
            }
            exist[c[j]]=1;
        }
        if(ans[i]!=-1){
            ans[i]=0;
        }
    }
    for(int i=1;i<=q;i++){
        int x=read();
        int y=read();
        c[x]=y;
        for(int j=1;j<=m;j++){
            if(l[j]<=x&&x<=r[j]&&ans[j]==-1){
                for(int k=1;k<=n;k++){
                    exist[k]=0;
                }
                ans[j]=-2;
                for(int k=l[j];k<=r[j];k++){
                    if(exist[c[k]]){
                        ans[j]=-1;
                        break;
                    }
                    exist[c[k]]=1;
                }
                if(ans[j]==-2){
                    ans[j]=i;
                }
            }
        }
    }
    int fans=0;
    for(int i=1;i<=m;i++){
        if(ans[i]==-1){
            ans[i]=i+m;
        }
        fans=fans^ans[i];
    }
    printf("%d",fans);
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

