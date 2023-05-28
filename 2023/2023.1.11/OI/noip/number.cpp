#include<cstdio>
#include<algorithm>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE long long
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

long long arr[10010];

bool cmp(int a,int b){
    return a>b;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	#endif

    register long long i;
    int n=read();int k=read();
    for(i=0;i<n;++i) arr[i]=read();
    std::nth_element(arr,arr+k-1,arr+n);
    long long a=-arr[k-1];
    std::nth_element(arr,arr+k-1,arr+n,cmp);
    a+=arr[k-1];
    for(i=2;i*i<=n;++i)
        if(!(a%i)){
            puts("NO");
            goto loop;
        }
    puts("YES");
    loop:print(a);

	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}