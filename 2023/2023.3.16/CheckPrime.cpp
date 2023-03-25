#include<cstdio>
#include<random>
#include<ctime>
#define int long long
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}
std::mt19937_64 mt(time(NULL));
int power(int a,int b,int mod){
	if(b==0){
		return 1;
	}
	if(b%2==1){
		return (power(a,b-1,mod)*a)%mod;
	}else{
		int temp=power(a,b/2,mod);
		return (temp*temp)%mod;
	}
}
bool check(int a){
	if(a<3||a%2==0){
		return a==2;
	}
	int n=a-1;
	int t=0;
	while(!(n%2)){
		n/=2;
		t++;
	}
	for(int i=1;i<=8;i++){
		int x=mt()%(a-2)+2;
		int v=power(x,n,a);
		if(v==1){
			break;
		}
		int j;
		for(j=0;j<t;j++){
			if(v==a-1){
				break;
			}
			v=(v*v)%a;
		}
		if(j>=t){
			return 0;
		}
	}
	return 1;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif
	int n;
	while(scanf("%lld",&n)!=EOF){
		printf("%d\n",check(n));
	}
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}