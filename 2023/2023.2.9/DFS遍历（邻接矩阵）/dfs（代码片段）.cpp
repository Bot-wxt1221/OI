//���ǻ����ڽӾ���ı����������Ҫ�����Ըĳɻ����ڽӱ�ı�����
bool visited[N];
void DFS(int start)
{
	visited[start] = true;
	// �����start
	cout << start << ' ';
	for (int i = 0; i < n; i++)
	if ((!visited[i]) && (G[start][i]!=INF))
	DFS(i);
}
//���ã�
memset(visited,0,sizeof(visited));
for (int i = 0; i < n; i++)
	if (!visited[i]) DFS(i);
