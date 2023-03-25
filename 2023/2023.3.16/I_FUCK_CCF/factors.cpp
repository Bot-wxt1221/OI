#include<cstdio>
#include <cmath>
#define int long long
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("factors.in", "r", stdin);
	freopen("factors.out", "w", stdout);
	#endif
    int x=read(),y=read();
    int ans=1;
    int tempx=x;
    bool a=1;
    for(int i=2;i<=sqrt(tempx);i++){
        a=0;
        int aa=0;
        while(x%i==0){
            aa++;
            aa%=10007;
            x=x/i;
        }
        aa=(aa*y)%10007;
        aa++;
        aa%=10007;
        ans=ans*aa;
        ans%=10007;
    }
    if(x!=1){
        ans*=(y+1)%10007;
        ans%=10007;
    }
    printf("%lld",ans);
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