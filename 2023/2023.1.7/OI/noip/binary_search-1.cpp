#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int arr[100010];

int* lower_bound(int *first,int *last,int key){
    register int left=0,right=last-first,mid;
    while(left<right){
        mid=(left+right)>>1;
        if(arr[mid]<key) left=mid+1;
        else right=mid;
    }
    return first+left;
}

int main(){
	#ifdef file
	freopen("binary_search.in", "r", stdin);
	freopen("binary_search.out", "w", stdout);
	#endif

    register int i,j,ans=0,now,pos;
    int n=read();
    for(i=0;i<n;++i) arr[i]=read();
    // std::sort(arr,arr+n);
    int m=read();
    for(i=0;i<m;++i){
        now=read();
        pos=std::lower_bound(arr,arr+n,now)-arr;
        if(arr[pos]==now) ++ans;
    }

    print(ans);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}