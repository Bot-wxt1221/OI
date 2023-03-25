#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int p=1000000007ll;
class matrix{
    public:
        int n,m;
        int map[5][5];
        matrix(int nn,int mm,int f){
            n=nn;
            m=mm;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    map[i][j]=0;
                }
            }
            for(int i=1;i<=std::min(n,m);i++){
                map[i][i]=f;
            }
        }
};
matrix operator * (matrix a,matrix b){
	matrix ans(a.n,b.m,0);
	for(int k=1;k<=a.m;k++){
		for(int i=1;i<=a.n;i++){
			for(int j=1;j<=b.m;j++){
				ans.map[i][j]+=a.map[i][k]*b.map[k][j];
				ans.map[i][j]%=p;
			}
		}
	}
	return ans;
}
matrix pow(matrix a,int v){
	if(v==0){
		matrix ans(a.n,a.n,1);
		return ans;
	}
	if(v%2==0){
		matrix b=pow(a,v/2);
		return b*b;
	}
	return pow(a,v-1)*a;
}
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
	int T=read();
	while(T--){
		matrix yuan(1,2,0);
		yuan.map[1][1]=1;
		yuan.map[1][2]=0;
		matrix po(2,2,0);
		po.map[2][1]=po.map[1][2]=po.map[2][2]=1;
		po.map[1][1]=0;
		int n=read();
		if(n==1){
			printf("1\n");
			continue;
		}
		po=pow(po,n-1);
		matrix temp=yuan*po;
		int ans=0;
		ans+=temp.map[1][2];
		ans%=p;
		matrix yuan1(1,2,0);
		yuan1.map[1][1]=0;
		yuan1.map[1][2]=1;
		// po1=pow(po1,n-1);
		temp=yuan1*po;
		// int p=1000000007ll;
		ans+=temp.map[1][1];
		ans%=p;
		ans+=temp.map[1][2];
		ans%=p;
		printf("%lld\n",ans);
	}
	return 0;
}
inline int read(){
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
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


