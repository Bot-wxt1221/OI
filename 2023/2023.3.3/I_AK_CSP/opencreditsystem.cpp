#include<cstdio>
#include <iostream>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
	#ifndef ONLINE_JUDGE
	freopen("opencreditsystem.in", "r", stdin);
	freopen("opencreditsystem.out", "w", stdout);
	#endif
    int T=read();
    while(T--){
        int n=read();
        int _max=-0x3f3f3f3f;
        int ans=-0x3f3f3f3f;
        for(int i=1;i<=n;i++){
            int temp=read();
            ans=std::max(ans,_max-temp);
            _max=std::max(_max,temp);
        }
        print(ans);
        putchar('\n');
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