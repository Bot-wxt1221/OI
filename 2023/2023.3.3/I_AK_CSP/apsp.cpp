#include <iostream>
#include<cstdio>
#include <cstring>
#define int long long
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}
int map[105][105];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("apsp.in", "r", stdin);
	freopen("apsp.out", "w", stdout);
	#endif
    int n=read();
    int m=read();
    memset(map,0x3f,sizeof(map));
    for(int i=0;i<n;i++){
        map[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int a=read();
        int b=read();
        map[a][b]=read();
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(map[i][k]==0x3f3f3f3f3f3f3f3fll){
                continue;
            }
            for(int j=0;j<n;j++){
                if(map[i][k]!=0x3f3f3f3f3f3f3f3fll&&map[k][j]!=0x3f3f3f3f3f3f3f3fll)
                    map[i][j]=std::min(map[i][j],map[i][k]+map[k][j]);
            }
        }
    }
    bool ans=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(map[i][k]==0x3f3f3f3f3f3f3f3fll){
                continue;
            }                                                                    
            for(int j=0;j<n;j++){
                if(map[i][k]!=0x3f3f3f3f3f3f3f3fll&&map[k][j]!=0x3f3f3f3f3f3f3f3fll)
                    if(map[i][j]>std::min(map[i][j],map[i][k]+map[k][j])){
                        printf("NEGATIVE CYCLE");
                        return 0;
                    }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==0x3f3f3f3f3f3f3f3fll){
                printf("INF ");
            }else{
                printf("%lld ",map[i][j]);
            }
        }
        printf("\n");
    }
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}