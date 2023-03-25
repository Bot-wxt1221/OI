#include<cstdio>
#include<bitset>
#include <cstring>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
int a[1005];
INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);
int hash[10000007];
int hash2[10000006];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("draw_lots.in", "r", stdin);
	freopen("draw_lots.out", "w", stdout);
	#endif
    int T=read();
    while(T--){
        int n=read(),m;
        m=read();
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        // b.clear();
        memset(hash,0,sizeof(hash));
        memset(hash2,0,sizeof(hash2));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // if(i!=j){
                    hash[(a[i]+a[j])%10000007]=1;
                    hash2[(a[i]+a[j])%10000006]=1;
                // }
            }
        }
        bool yes=0;
        for(int i=1;i<=n&&!yes;i++){
            for(int j=1;j<=n&&!yes;j++){
                // if(i!=j){
                    if((m-a[i]-a[j])>=0&&hash[(m-a[i]-a[j])%10000007]&&hash2[(m-a[i]-a[j])%10000006]&&!yes){
                        printf("Yes\n");
                        yes=1;
                        break;
                    // }
                }
            }
        }
        if(!yes)
            printf("No\n");
    }
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||'9'<c)f=(c=='-'),c=getchar();
    while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}

void print(OUTPUT_DATA_TYPE x){
    register char s[20];
    register int i=0;
    if(x<0){
        x=-x;
        putchar('-');
    }
    if(x==0){
        putchar('0');
        return;
    }
    while(x){
        s[i++]=x%10;
        x/=10;
    }
    while(i){
        putchar(s[--i]+'0');
    }
    return;
}