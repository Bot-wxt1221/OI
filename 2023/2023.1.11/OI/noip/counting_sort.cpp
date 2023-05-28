#include<cstdio>
#include<algorithm>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int arr[2000010],b[2000010],c[10010];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("counting_sort.in", "r", stdin);
	freopen("counting_sort.out", "w", stdout);
	#endif

    register int i,max=0;
    int n=read();
    for(i=1;i<=n;++i) arr[i]=read(),max=std::max(arr[i],max);
    for(i=1;i<=n;++i) ++c[arr[i]];
    for(i=1;i<=max;++i) c[i]+=c[i-1];
    for(i=n;i;--i)
        b[c[arr[i]]--]=arr[i];
    for(i=1;i<=n;++i){
        print(b[i]);
        putchar(' ');
    }

	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}