//这是基于邻接矩阵的遍历。如果需要，可以改成基于邻接表的遍历。
queue<int> q;
bool visited[N];
void BFS(int start)
{
	q.push(start); 
	visited[start] = true;
	do
	{
		int a = q.front(); q.pop();
		// 处理点a
		cout << a << ' ';
		for (int i = 0; i < n; i++)
		if ((!visited[i]) && (G[a][i] != INF))
		{
			q.push(i);
			visited[a] = true;
		}
	} while (!q.empty());
}
//调用：
memset(visited,0,sizeof(visited));
for (int i = 0; i < n; i++)
	if (!visited[i]) BFS(i);
