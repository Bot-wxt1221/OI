#include<cstdio>
#include<algorithm>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int arr[1000010],bak[1000010];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("subarray.in", "r", stdin);
	freopen("subarray.out", "w", stdout);
	#endif

    int n=0,ans=0x7fffffff;
    register int i;
    while(~scanf("%d",&i)) arr[n]=i,bak[n++]=i;
    std::sort(arr,arr+n);
    for(i=0;i<n;++i){
        if(arr[i]!=bak[i]){
            ans=-i;
            break;
        }
    }

    if(ans==0x7fffffff){
        putchar('0');
        return 0;
    }

    for(i=n-1;i>=0;--i){
        if(arr[i]!=bak[i]){
            ans+=i;
            break;
        }
    }

    print(ans+1);

	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}