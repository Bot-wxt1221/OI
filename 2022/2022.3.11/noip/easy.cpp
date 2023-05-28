
/*
枚举一个一个的加，配合位运算加速即可AC 
*/
#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
int have(int n){//求二进制含1个数 
	int ans=0;
	while(n){
		ans+=(n&1);
		n=n>>1; 
	}
	return ans;
}
signed main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	int a=read();
	while(a!=0){
		int temp=a+1,ah=have(a);
		while(1){
			if(have(temp)==ah){
				cout<<temp<<endl;
				break;
			}
			temp++;
		}
		a=read();
	}
	return 0;
}

