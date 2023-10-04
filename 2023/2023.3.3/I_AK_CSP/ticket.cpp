#include<cstdio>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE unsigned long long
#define OUTPUT_DATA_TYPE unsigned long long
unsigned long long map[50][50];
INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

signed main(){
	#ifndef ONLINE_JUDGE
	freopen("ticket.in", "r", stdin);
	freopen("ticket.out", "w", stdout);
	#endif
    int n=read();
    map[0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            map[i][j]+=map[i-1][j]+map[i][j-1];
        }
    }
    printf("%lld",map[n][n]);
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