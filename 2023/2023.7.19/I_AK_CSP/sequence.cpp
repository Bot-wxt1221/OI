#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define mod 1000000007
#define l6 166666668
int read(){
	int x=0,op=1;
	char f=getchar();
	while(f<'0'||f>'9'){
		op=((f=='-')?-1:1);
		f=getchar();
	}
	while('0'<=f&&f<='9'){
		x=(x<<3)+(x<<1)+(f^'0');
		f=getchar();
	}
	return op*x;
}
class Matrix{
	public:
		int map[5][5];
		Matrix(){
			memset(map,0,sizeof(map));
			map[1][1]=map[2][2]=1;
		}
};
Matrix operator * (Matrix a,Matrix b){
	Matrix c;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
			c.map[i][j]=0;
			for(int k=1;k<=2;k++){
				c.map[i][j]+=(a.map[i][k]*b.map[k][j])%mod;
				c.map[i][j]%=mod;
			}
		}
	}
	return c;
}
int a[1000005];
Matrix temp3[1000005];
Matrix temp4[1000005];
Matrix temp,temp2;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	#endif
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	temp.map[1][2]=temp.map[2][1]=0;
	temp.map[1][1]=temp.map[2][2]=1;
	for(int i=1;i<=n;i++){
		temp2.map[1][1]=(((((a[i])*(a[i]+1))%mod-((a[i])*(a[i]+1)/2)%mod)%mod)+mod)%mod;
		temp2.map[1][2]=(((((a[i])*(a[i]+1))/2)%mod)*a[i])%mod;
		temp2.map[1][2]-=((((a[i]*(a[i]+1))%mod)*(2*a[i]+1))%mod*l6)%mod;
		temp2.map[1][2]%=mod;
		temp2.map[1][2]+=mod;
		temp2.map[1][2]%=mod;
		temp2.map[2][1]=(a[i])%mod;
		temp2.map[2][2]=(((a[i])*(a[i]+1))/2)%mod;
		temp2.map[2][2]+=mod-a[i];
		temp2.map[2][2]%=mod;
		temp=temp2*temp;
		temp3[i]=temp;
	}
	temp.map[1][2]=temp.map[2][1]=0;
	temp.map[1][1]=temp.map[2][2]=1;
	for(int i=n;i>=1;i--){
		temp2.map[1][1]=(((((a[i])*(a[i]+1))%mod-((a[i])*(a[i]+1)/2)%mod)%mod)+mod)%mod;
		temp2.map[1][2]=(((((a[i])*(a[i]+1))/2)%mod)*a[i])%mod;
		temp2.map[1][2]-=((((a[i]*(a[i]+1))%mod)*(2*a[i]+1))%mod*l6)%mod;
		temp2.map[1][2]%=mod;
		temp2.map[1][2]+=mod;
		temp2.map[1][2]%=mod;
		temp2.map[2][1]=(a[i]+1)%mod;
		temp2.map[2][2]=(((a[i])*(a[i]+1))/2)%mod;
		temp=temp*temp2;
		temp4[i]=temp;
	}
	temp4[n+1].map[1][1]=temp4[n+1].map[2][2]=temp3[0].map[1][1]=temp3[0].map[2][2]=1;
	int ans=temp4[2].map[2][2]*a[1]+temp4[2].map[1][2];
	ans%=mod;
	for(int i=2;i<=n;i++){
		Matrix temp1=temp3[i-1]*temp4[i+1];
	int ans1=(temp1.map[2][2]*a[i]+temp1.map[1][2])%mod;
		ans+=ans1;
		ans%=mod;
	}
	printf("%lld",ans);
	return 0;
}

