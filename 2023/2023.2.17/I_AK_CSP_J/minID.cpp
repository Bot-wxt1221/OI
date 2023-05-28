#include<cstdio>
#include<iostream>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
int a[1000005];
INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
	#ifndef ONLINE_JUDGE
	freopen("minID.in", "r", stdin);
	freopen("minID.out", "w", stdout);
	#endif
    int n=read();
    int nn=n;
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    int R=1;
    int L=n;
    int ans=0;
    while(n>1){
        int i,j;
        for(i=0,j=-1;i<(L-R)+1;i++){
            if(a[R+i]<(L-R+1)/2+ans){
                std::swap(a[R+i],a[(++j)+R]);
            }
        }
        if(j+1==(n/2)){
            ans+=(n/2);
            R+=j+1;
            n=(L-R)+1;
        }else{
            L=j+1+R;
            n=(L-R)+1;
        }
    }
    if(R==nn){
        ans++;
	}
    printf("%d",ans?ans:0);
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
