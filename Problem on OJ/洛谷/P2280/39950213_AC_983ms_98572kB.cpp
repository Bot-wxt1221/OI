#include <iostream>
#include <cstdio>
inline int read();
int map[5010][5010];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("laserbomb.in","r",stdin);
	freopen("laserbomb.out","w",stdout);
	#endif
    int n=read(),r=read();
    for(int i=1;i<=n;i++){
        int x=read(),y=read();
        map[x][y]+=read();
    }
    for(int i=0;i<=5005;i++){
        for(int j=0;j<=5005;j++){
            if(i-1>=0){
                map[i][j]+=map[i-1][j];
            }
            if(j-1>=0){
                map[i][j]+=map[i][j-1];
            }
            if(i-1>=0&&j-1>=0){
                map[i][j]-=map[i-1][j-1];
            }
            // map[i][j]+=map[i-1][j]+map[i][j-1]-map[i-1][j-1];
        }
    }
    int _max=-40000;
    for(int i=0;i<=5005-r;i++){
        for(int j=0;j<=5005-r;j++){
            int ai=i+r-1;
            int aj=j+r-1;
            int ans=map[ai][aj];
            // map[ai][aj]-map[ai][j-1]-map[i-1][aj]+map[i-1][j-1]
            if(j-1>=0){
                ans-=map[ai][j-1];
            }
            if(i-1>=0){
                ans-=map[i-1][aj];
            }
            if(j-1>=0&&i-1>=0){
                ans+=map[i-1][j-1];
            }
            _max=std::max(ans,_max);
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


