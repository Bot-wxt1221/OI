#include <iostream>
#include <cstdio>
inline int read();
int map[5005][5005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("laserbomb.in","r",stdin);
	freopen("laserbomb.out","w",stdout);
	#endif
    int n=read(),R=read();
    if(R<1){
        printf("0\n");
        return 0;
    }
    R-=1;
    for(int i=1;i<=n;i++){
        int x=read()+1;
        int y=read()+1;
        int z=read();
        map[x][y]=z;
    }
    for(int i=1;i<=5001;i++){
        for(int j=1;j<=5001;j++){
            map[i][j]+=map[i][j-1]+map[i-1][j]-map[i-1][j-1];
        }
    }
    int _max=-40000;
    for(int i=1;i+R<=5001;i++){
        for(int j=1;j+R<=5001;j++){
            int x=i+R;
            int y=j+R;
            _max=std::max(_max,map[x][y]-map[i-1][y]-map[x][j-1]+map[i-1][j-1]);
        }
    }
    printf("%d",_max);
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


