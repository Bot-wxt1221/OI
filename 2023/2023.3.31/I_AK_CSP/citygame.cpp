#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
bool map[1005][1005];
int l[1005][1005];
int r[1005][1005];
int h[1005][1005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("citygame.in","r",stdin);
	freopen("citygame.out","w",stdout);
	#endif
    int k=read();
    while(k--){
        int n=read(),m;
        m=read();
        memset(map,0,sizeof(map));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        memset(h,0,sizeof(h));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char a=' ';
                while(a!='R'&&a!='F'){
                    a=getchar();
                }
                map[i][j]=((a=='F')?1:0);
                l[i][j]=((a=='F')?(l[i][j-1]+1):0);
                h[i][j]=((a=='F')?(h[i-1][j]+1):0);
            }
            for(int j=m;j>=1;j--){
                r[i][j]=((map[i][j])?(r[i][j+1]+1):0);
            }
        }
        int ans=0;
        for(int j=1;j<=m;j++){
            int ml=0x3f3f3f3f,mr=0x3f3f3f3f;
            int h=0;
            for(int i=1;i<=n;i++){
                if(map[i][j]){
                    ml=std::min(ml,l[i][j]);
                    mr=std::min(mr,r[i][j]);
                    h++;
                    ans=std::max(ans,(mr+ml-1)*h);
                }else{
                    ml=0x3f3f3f3f,mr=0x3f3f3f3f;
                    h=0;
                }
            }
        }
        printf("%d\n",ans*3);
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


