#include <iostream>
#include <cstdio>
using namespace std;
long long read(){
	char temp=getchar();
	long long f=1,x=0;
	while('0'>temp||temp>'9'){
		(temp=='-')?(f=-1):(1);
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
long long a[5005];
long long b[5005];
long long a1[5005][5005];//a max+
long long b1[5005][5005];//a min+
long long c1[5005][5005];//a max-
long long d1[5005][5005];//a min-
bool e1[5005][5005];//a 0
long long f1[5005][5005];//b min
long long g1[5005][5005];//b max
signed main(){
	// freopen("game.in","r",stdin);
	// freopen("game.out","w",stdout);
	long long n=read(),m,q;
	m=read();
	q=read();
	for(long long i=1;i<=n;i++){
		long long a=read();
		::a[i]=a;
		if(a>0){
			a1[i][i]=a;
			b1[i][i]=a;
			c1[i][i]=-0x3f3f3f3f3f3f3f3fll;
			d1[i][i]=0x3f3f3f3f3f3f3f3fll;
		}else if(a==0){
			c1[i][i]=-0x3f3f3f3f3f3f3f3fll;
			d1[i][i]=0x3f3f3f3f3f3f3f3fll;
			a1[i][i]=-0x3f3f3f3f3f3f3f3fll;
			b1[i][i]=0x3f3f3f3f3f3f3f3fll;
			e1[i][i]=1;
		}else{
			a1[i][i]=-0x3f3f3f3f3f3f3f3fll;
			b1[i][i]=0x3f3f3f3f3f3f3f3fll;
			c1[i][i]=a;
			d1[i][i]=a;
		}
	}
	for(long long i=1;i<=m;i++){
		f1[i][i]=g1[i][i]=read();
		b[i]=f1[i][i];
	}
	for(long long k=2;k<=n;k++){
		for(long long i=1;(i+k-1)<=n;i++){
			long long j=i+k-1;
			a1[i][j]=max(a1[i][j-1],a1[j][j]);
			e1[i][j]=e1[i][j-1]||e1[j][j];
			b1[i][j]=min(b1[i][j-1],b1[j][j]);
			c1[i][j]=max(c1[i][j-1],c1[j][j]);
			d1[i][j]=min(d1[i][j-1],d1[j][j]);
		}
	}
	for(long long k=2;k<=m;k++){
		for(long long i=1;(i+k-1)<=m;i++){
			long long j=i+k-1;
			f1[i][j]=min(f1[i][j-1],f1[j][j]);
			g1[i][j]=max(g1[i][j-1],g1[j][j]);
		}
	}
	for(long long i=1;i<=q;i++){
		long long l1,r1,l2,r2;
		l1=read();
		r1=read();
		l2=read();
		r2=read();
		if(g1[l2][r2]<0){//all <0
			if(d1[l1][r1]!=0x3f3f3f3f3f3f3f3fll)
				printf("%lld\n",g1[l2][r2]*d1[l1][r1]);
			else if(b1[l1][r1]!=0x3f3f3f3f3f3f3f3fll){
				printf("%lld\n",g1[l2][r2]*b1[l1][r1]);
			}
				
		}else if(f1[l2][r2]>0){//all >0
			if(a1[l1][r1]!=-0x3f3f3f3f3f3f3f3fll){
				printf("%lld\n",a1[l1][r1]*f1[l2][r2]);
			}else if(c1[l1][r1]!=-0x3f3f3f3f3f3f3f3fll){
				printf("%lld\n",c1[l1][r1]*f1[l2][r2]);
			}
		}else{
			if(e1[l1][r1]){
				printf("0\n");
			}else{
				long long ans=-0x3f3f3f3f3f3f3f3fll;
				if(b1[l1][r1]!=0x3f3f3f3f3f3f3f3fll){
					ans=max(ans,b1[l1][r1]*f1[l2][r2]);
				}else if(c1[l1][r1]!=0x3f3f3f3f3f3f3f3fll){
					ans=max(ans,c1[l1][r1]*g1[l2][r2]);
				}
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}

