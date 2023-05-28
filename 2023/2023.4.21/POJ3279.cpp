#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int map[20][20];
int map2[20][20];
int anas[20][20];
int ans2[20][20];
int vised[20];
int n,m;
int min=0x3f3f3f3f;
int calc(){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vised[i-1]){
            map2[1][i]^=1;
            map2[1][i-1]^=1;
            map2[1][i+1]^=1;
            map2[2][i]^=1;
            ans++;
            anas[1][i]=1;
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<=n;j++){
            if(map2[i][j]){
                map2[i][j]^=1;
                map2[i+1][j]^=1;
                map2[i+1][j-1]^=1;
                map2[i+1][j+1]^=1;
                map2[i+2][j]^=1;
                ans++;
                anas[i+1][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(map2[m][i]){
            return 0x3f3f3f3f;
        }
    }
    return ans;
}
void dfs(int step){
    if(step==0){
        memset(anas,0,sizeof(anas));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                map2[i][j]=map[i][j];
            }
        }
        int temp=calc();
        if(temp<min){
            min=temp;
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    ans2[i][j]=anas[i][j];
                }
            }
        }
        return ;
    }
    dfs(step-1);
    vised[step-1]=1;
    dfs(step-1);
    vised[step-1]=0;
    return ;
}
int main(){
    m=read();
    n=read();
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            map[i][j]=read();
        }
    }
    dfs(n);
    if(min==0x3f3f3f3f){
        printf("IMPOSSIBLE");
    }else{
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){  
                printf("%d ",ans2[i][j]);
            }
            printf("\n");
        }
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


