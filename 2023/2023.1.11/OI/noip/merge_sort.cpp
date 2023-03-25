#include<cstdio>
#include<cstring>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int arr[500010],lc[500010],rc[500010],ans;

void merge(int l,int r,int mid){
    register int i,lp,rp;
    lc[mid]=0x7f7f7f7f;
    rc[r]=0x7f7f7f7f;
    for(i=l;i<mid;++i) lc[i]=arr[i];
    for(i=mid;i<r;++i) rc[i]=arr[i];
    for(i=lp=l,rp=mid;i<r;++i){
        ans++;
        if(lc[lp]<=rc[rp]) arr[i]=lc[lp++];
        else arr[i]=rc[rp++];
    }
}

void mergesort(int l,int r){
    if(l+1<r){
        int mid=(l+r)>>1;
        mergesort(l,mid);
        mergesort(mid,r);
        merge(l,r,mid);
    }
}

int main(){
	#ifdef file
	freopen("merge_sort.in", "r", stdin);
	freopen("merge_sort.out", "w", stdout);
	#endif

    register int i;
    int n=read();
    for(i=0;i<n;++i) arr[i]=read();
    mergesort(0,n);
    for(i=0;i<n;++i){
        print(arr[i]);
        putchar(' ');
    }

    putchar('\n');
    print(ans);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}