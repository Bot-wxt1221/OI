#include <iostream>
#include <cstdio>
using namespace std;
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
int map[1005][1005];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
    int m=read();
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            map[i][j]=read();
        }
    }
    for(int i=1;i<=n;i++){
        int x=0,y=0;
        for(int j=1;j<=m;j++){
            if(map[j][i]==1){
                x++;
            }else{
                y++;
            }
        }
        if(x>y){
            map[0][i]=1;
        }else{
            map[0][i]=0;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(read()==map[0][i]){
            ans++;
        }
    }
    printf("%d",ans);
	return 0;
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

