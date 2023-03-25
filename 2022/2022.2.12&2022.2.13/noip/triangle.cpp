#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,-1,-1,-1,0,1,1,1};
class node{
	int x,y;
};
int g[20][20][8]={0};
int f[20][20][8]={0};
int gun[5005][4];
signed main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b,c,d;
		cin>>gun[i][0]>>gun[i][1]>>gun[i][2]>>gun[i][3];
		for(int j=0;j<8;j++){
			if(((gun[i][2]-gun[i][0])==dx[j])&&((gun[i][3]-gun[i][1])==dy[j])){
				g[gun[i][2]][gun[i][3]][(j+4)%8]=true;
				g[gun[i][0]][gun[i][1]][j]=true;
			}
		}
	}
	for(int x1=0;x1<=10;x1++){
		for(int y1=0;y1<=10;y1++){
			for(int d=0;d<=7;d++){
				int i=0,x2=x1,y2=y1;
				while(x2>=0&&x2<=10&&y2>=0&&y2<=10&&g[x2][y2][d]==1){
					i++;x2+=dx[d],y2+=dy[d];
				}
				f[x1][y1][d]=i;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=10;i++){
		for(int j=0;j<=10;j++){
			for(int m=1;m<=f[i][j][0];m++){
				if(f[i][j][6]>=m&&f[i+m][j][5]>=m)	ans++;
				if(f[i][j][7]>=m&&f[i+m][j][6]>=m)	ans++;
				if(f[i][j][2]>=m&&f[i+m][j][3]>=m)	ans++;
				if(f[i][j][1]>=m&&f[i+m][j][2]>=m)	ans++;
				if((f[i][j][7]>=m/2.0&&f[i+m][j][5]>=m/2.0))	ans++;
				if((f[i][j][1]>=m/2.0&&f[i+m][j][3]>=m/2.0))	ans++;
			}
			for(int m=1;m<=f[i][j][6];m++){
				if((f[i][j][5]>=m/2.0&&f[i][j+m][3]>=m/2.0))	ans++;
				if((f[i][j][7]>=m/2.0&&f[i][j+m][1]>=m/2.0))	ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

