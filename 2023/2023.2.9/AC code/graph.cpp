#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int map[305][306];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	#endif
    int a=0;
    int n=read();
    while(n--){
        a++;
        int m=read(),k;
        k=read();
        memset(map,0,sizeof(map));//初始化
        for(int i=1;i<=k;i++){
            int x=read()+1;
            int y=read()+1;
            map[x][y]=1;
        }
        int ans=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                int f1=0,f2=0;
                for(int aa=1;aa<=m;aa++){
                    if(map[i][aa]&map[j][aa]){//当前枚举的i(uv)和j(xy)都指向同一个点 ，说明x和y是同一个数
                        f1=1;
                    }
                    if(map[i][aa]^map[j][aa]){//当前枚举的i(uv)和j(xy)只有一个指向这个点 ，说明x和y不是同一个数
                        f2=1;
                    }
                }
                if(f1==1&&f2==1){//产生矛盾
                    ans=0;
                    break;
                }
            }
        }
        if(ans){
            printf("Case #%d: Yes\n",a);
        }else{
            printf("Case #%d: No\n",a);
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


