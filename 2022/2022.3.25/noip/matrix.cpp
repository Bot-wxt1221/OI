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
int main(){
//	freopen("matrix.in","r",stdin);
//	freopen("matrix.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			b[i][j]+=a[i][j];
			b[i][j]+=b[i][j-1];
			for(int aj=1;aj<i;aj++){
				b[i][j]+=a[aj][j];
			}
//			cout<<b[i][j]<<' ';
		}
//		cout<<endl;
	}
	int ans=-1270000005;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int i2=i+1;i2<=n;i2++){
				for(int j2=j+1;j2<=n;j2++){
					int aa=b[i2][j2]-b[i2][j-1]-b[i-1][j2]+b[i-1][j-1];
					ans=max(ans,aa);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

