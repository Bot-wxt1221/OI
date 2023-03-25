//这是基于邻接矩阵的遍历。如果需要，可以改成基于邻接表的遍历。
bool visited[N];
void DFS(int start)
{
	visited[start] = true;
	// 处理点start
	cout << start << ' ';
	for (int i = 0; i < n; i++)
	if ((!visited[i]) && (G[start][i]!=INF))
	DFS(i);
}
//调用：
memset(visited,0,sizeof(visited));
for (int i = 0; i < n; i++)
	if (!visited[i]) DFS(i);
