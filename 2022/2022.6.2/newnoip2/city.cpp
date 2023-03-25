#include <iostream>
#include <cstdio>
#include <cstring>
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
int w[1005];
int st[1005];
int top=0;
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
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
    	memset(w,0,sizeof(w));
    	top=0;
    	for(int j=1;j<=m+1;j++){
    		if(st[top]<_max[i][j]){
    			st[++top]=_max[i][j];
    			w[top]=1;
    			continue;
    		}else{
    			int a=0;
    			while(st[top]>_max[i][j]&&top>0){
    				a+=w[top];
    				ans=max(ans,st[top]*a);
    				top--;
    			}
    			w[++top]=a+1;
    			st[top]=_max[i][j];
    		}
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


