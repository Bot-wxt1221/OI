#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int map[25][25][25];
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen("garbageheap.in","r",stdin);
	// freopen("garbageheap.out","w",stdout);
	#endif
    int t=read();
    while(t--){
        int a=read(),b,c;
        b=read();
        c=read();
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                for(int m=1;m<=c;m++){
                    map[i][j][m]=read();
                    map[i][j][m]+=map[i-1][j][m]+map[i][j-1][m]+map[i][j][m-1]-map[i-1][j-1][m]-map[i-1][j][m-1]-map[i][j-1][m-1]+map[i-1][j-1][m-1];
                }
            }
        }
        int _max=-0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                for(int m=1;m<=c;m++){
                    for(int ai=i;ai<=a;ai++){
                        for(int bj=j;bj<=b;bj++){
                            for(int bm=m;bm<=c;bm++){
                                _max=std::max(_max,map[ai][bj][bm]-map[i-1][bj][bm]-map[ai][j-1][bm]-map[ai][bj][m-1]+map[i-1][j-1][bm]+map[i-1][bj][m-1]+map[ai][j-1][m-1]-map[i-1][j-1][m-1]);
                            }
                        }
                    }
                }
            }
        }
        printf("%lld\n\n",_max);
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


