#include<cstdio>
#include<algorithm>
#include<algorithm>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE long long
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int sorted[10010],arr[10010],pos[10010],x=0x3f3f3f3f;
char book[10010];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("min_cost_sort.in", "r", stdin);
	freopen("min_cost_sort.out", "w", stdout);
	#endif

    register int i,j,tot=0,u,bak,min,k;
	register long long sum,ans=0;
    int n=read();
    for(i=0;i<n;++i) arr[i]=sorted[i]=read(),x=std::min(x,arr[i]);
	std::sort(sorted,sorted+n);
	for(i=0;i<n;++i) pos[sorted[i]]=i;
	for(i=0;i<n;++i)
		if(!book[i]){
			u=pos[arr[i]];
			min=arr[i];
			book[i]=1;
			sum=arr[i];
			k=1;
			while(u!=i){
				book[u]=1;
				min=std::min(arr[u],min);
				sum+=arr[u];
				u=pos[arr[u]];
				++k;
			}
			ans+=std::min(sum+min+(k+1)*x,sum+(k-2)*min);
		}

	print(ans);



	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
