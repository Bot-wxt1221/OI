#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int arr[100010],q[50010];

int main(){
	#ifdef file
	freopen("binary_search.in", "r", stdin);
	freopen("binary_search.out", "w", stdout);
	#endif

    register int i,j,ans=0,have;
    int n=read();
    for(i=0;i<n;++i) arr[i]=read();
    int m=read();
    for(i=0;i<m;++i) q[i]=read();
    std::sort(q,q+m);
    for(i=j=0;i<m;++i){
        if(i&&q[i]==q[i-1]){
            ans+=have;
            continue;
        }
        have=0;
        while(j<n&&arr[j]<=q[i]){
            if(arr[j]==q[i]) have=1;
            j++;
        }
        ans+=have;
    }

    print(ans);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}