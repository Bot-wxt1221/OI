#include <iostream>
#include <cstdio>
namespace pro{
	long long read();
	int solve(){
		long long n=read();
		long long ls=-1;
		long long day=0;
		while(n>=1){
			day++;
			if(n%3==1&&ls==-1){
				ls=day;
			}
			n-=((n-1)/3+1);
		}
		printf("%lld %lld",day,ls);
		return 0;
	}
};
//10^10 
int main(){
//	freopen("apple.in","r",stdin);
//	freopen("apple.out","w",stdout);
	return pro::solve();
} 
long long pro::read(){
	long long f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		if(temp=='-'){
			f=-1;
		}
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
