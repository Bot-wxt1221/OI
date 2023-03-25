#include <iostream>
#include <queue>
#include <cstdio>
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

int a[105][105];//yuan
int b[105][105];
int c[105];
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=read();
//			cout<<b[i][j]<<' ';
			b[i][j]=a[i][j]+b[i][j-1];
		}
//		cout<<endl;
	}
	int ans=-1270000005;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int _min=0;
			for(int m=1;m<=n;m++){
				c[m]=b[m][j]-b[m][i-1];
				c[m]+=c[m-1];
			}
			for(int m=1;m<=n;m++){
				ans=max(ans,c[m]-_min);
//				if(ans==1346){
//					cout<<endl;
//				}
				_min=min(_min,c[m]);
			}
		}
	}
	cout<<ans;
	return 0;
}

