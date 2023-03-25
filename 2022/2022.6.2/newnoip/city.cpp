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
char map[1005][1005];
int _max[1005][1005];
int r[1005];
int l[1005];
int main(){
//	freopen("city.in","r",stdin);
//	freopen("city.out","w",stdout);
	int n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            map[i][j]=getchar();
            while(map[i][j]!='R'&&map[i][j]!='F'){
                map[i][j]=getchar();
            }
        }
	}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j]=='F'){
                _max[i][j]=_max[i-1][j]+1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
    	memset(l,0,sizeof(l));
    	memset(r,0,sizeof(r));
        for(int j=1;j<=m;j++){
            if(_max[i][j-1]>=_max[i][j]){
                r[j]=r[j-1]+1;
            }else{
                r[j]=1;
            }
        }
        for(int j=m;j>=1;j--){
            if(_max[i][j+1]>=_max[i][j]){
                l[j]=l[j+1]+1;
            }else{
                l[j]=1;
            }
        }
        for(int j=1;j<=m;j++){
            ans=max(ans,((r[j]+l[j]-1)*_max[i][j]));
        }
    }
    printf("%d",3*ans);
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


