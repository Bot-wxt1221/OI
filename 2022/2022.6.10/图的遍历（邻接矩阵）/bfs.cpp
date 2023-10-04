#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int a[1005][1005];
bool vis[1001];
int n,m;
void bfs(int u);

int main(void)
{
	freopen("graph.in","r",stdin);
	freopen("graph_bfs.out","w",stdout);
	memset(vis,false,sizeof(vis));
	memset(a,0,sizeof(a));
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x,y;
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}

	bfs(1);	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 

void bfs(int u)
{
	int q[1001];
	int head = 0, tail = 0;
	q[head] = u;
	tail++;
    vis[u] = true;
    while(head < tail)
    {
    	int p = q[head++];
    	cout << p << " ";
    	for(int i = 1; i <= n; i++)
    		if(a[p][i] == 1 && vis[i] == false)
    		{
    			q[tail++] = i;
    			vis[i] = true;
    		}
    }
	
	return;
}
