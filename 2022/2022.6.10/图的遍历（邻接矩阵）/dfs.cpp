#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int a[1005][1005];
bool vis[1001];
int n, m;
void dfs(int u);

int main(void)
{
	freopen("graph.in","r",stdin);
	freopen("graph_dfs.out","w",stdout);
	memset(a,0,sizeof(a));
	memset(vis,false,sizeof(vis));
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x,y;
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}	
	dfs(1);	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 

void dfs(int u)
{
	cout << u << " ";
	vis[u] = true;
	for(int i = 1; i <= n; i++)
		if(a[u][i] == 1 && vis[i] == false) dfs(i);
		
	return;
}
