#include<cstdio>
#include <cmath>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int cnt[1000005];

int minipr[1000005];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("factorial.in", "r", stdin);
	freopen("factorial.out", "w", stdout);
	#endif
    int n=read();
    for(int i=2;i<=n;i++){
        cnt[i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                minipr[i]=j;
                break;
            }
        }
    }
    for(int i=n;i>=2;i--){
        if(minipr[i]!=0){
            cnt[minipr[i]]+=cnt[i];
            cnt[i/minipr[i]]+=cnt[i];
            cnt[i]=0;
        }
    }
    for(int i=2;i<=n;i++){
        if(minipr[i]==0){
            printf("%d %d\n",i,cnt[i]);
        }
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