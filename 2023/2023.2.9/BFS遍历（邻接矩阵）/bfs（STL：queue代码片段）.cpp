//���ǻ����ڽӾ���ı����������Ҫ�����Ըĳɻ����ڽӱ�ı�����
queue<int> q;
bool visited[N];
void BFS(int start)
{
	q.push(start); 
	visited[start] = true;
	do
	{
		int a = q.front(); q.pop();
		// �����a
		cout << a << ' ';
		for (int i = 0; i < n; i++)
		if ((!visited[i]) && (G[a][i] != INF))
		{
			q.push(i);
			visited[a] = true;
		}
	} while (!q.empty());
}
//���ã�
memset(visited,0,sizeof(visited));
for (int i = 0; i < n; i++)
	if (!visited[i]) BFS(i);
