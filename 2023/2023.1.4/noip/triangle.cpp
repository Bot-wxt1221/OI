#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int arr[1000010];

int main(){
	#ifdef file
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	#endif
	
	register int i,ans=0,j;
	int n=read();
	for(i=0;i<n;++i) arr[i]=read();
	std::sort(arr,arr+n);
	
	for(i=0;i+2<n;++i){
		if(arr[i]+arr[i+1]>arr[i+2]) ans=std::max(ans,arr[i]+arr[i+1]+arr[i+2]);
	}


	
	print(ans);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
