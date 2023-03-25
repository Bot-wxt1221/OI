#include<cstdio>
#include <cmath>
#define int long long
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int power(int a,int b,int mod){
    if(b==0){
        return 1;
    }
    if(b%2){
        return (power(a,b-1,mod)*a)%mod;
    }else{
        int temp=power(a,b/2,mod);
        return (temp*temp)%mod;
    }
}

int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1;
        y=0;
        return a;
    }
    int temp=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return temp;
}
int inv(int a,int mod){
    int x,y;
    exgcd(a,mod,x,y);
    x%=mod;
    x+=mod;
    x%=mod;
    return x;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("factor_sum.in", "r", stdin);
	freopen("factor_sum.out", "w", stdout);
	#endif
    int x=read(),y=read();
    int ans=1;
    int tempx=x;
    for(int i=2;i<=sqrt(tempx);i++){
        int aa=0;
        while(x%i==0){
            aa++;
            // aa%=10007;
            x=x/i;
        }
        aa*=y;
        int temp=(power(i,aa+1,9901)+9900)%9901;
        ans=((ans)*((temp*((inv(i-1,9901))%9901))%9901))%9901;
    }
    if(x!=1){
        int aa=1;
        aa*=y;
        int temp=(power(x,aa+1,9901)+9900)%9901;
        ans=((ans)*((temp*((inv(x-1,9901))%9901))%9901))%9901;
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