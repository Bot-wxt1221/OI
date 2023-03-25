#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<set>
#include<ctime>
#include<stack>
#define ll long long
#define RI register int
#define RL register long long
using namespace std;
const int maxn=1e1+10;
typedef struct
{
	int x,y;
	int dir;
}node;
node d[3];
int n,m,cnt,ans;
int map[maxn][maxn];
ll path[maxn<<10];
bool v[maxn][maxn][maxn][maxn];
inline node wlk(node x,bool opt);
inline void dfs(node x,node las);
int main()
{
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	n++;m++;
	dfs((node){1,1,1},(node){1,1,1});
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
inline node wlk(node x,bool opt)
{
	register node ret=(node){x.x,x.y,x.dir};
	if(opt)
	{
		ret.dir++;
		if(ret.dir==5) ret.dir=1;	
	}
	if(ret.dir==1) ret.x++;
	else if(ret.dir==2) ret.y++;
	else if(ret.dir==3) ret.x--;
	else ret.y--;
	return ret;
}
inline void dfs(node x,node las)
{
	if(x.x>n || x.x<1 || x.y>m || x.y<1 || v[las.x][las.y][x.x][x.y]) return;
	else if(x.x==n && x.y==m)
	{
		ans++;
		return;
	}
	else
	{
		v[x.x][x.y][las.x][las.y]=v[las.x][las.y][x.x][x.y]=1;;
		for(RI i=0;i<=1;i++)
		{
			register node nex=wlk(x,i);
			dfs(wlk(x,i),x);
		}	
		v[x.x][x.y][las.x][las.y]=v[las.x][las.y][x.x][x.y]=0;
	}
}

