int first[N]; // first[u]表示从u出发的第一条 边的序号
int u[M],v[M],w[M], next[M]; // next[e]表示编号为e的下一条 边的序号

memset(first, -1, sizeof(first));
for (int e = 0; e < m; e++)
{
	cin >> u[e] >> v[e] >> w[e];
	next[e] = first[u[e]];  // 插入一条边
	first[u[e]] = e;
}

//如果想检查从 a 出发的所有边，那么可以
for (int e = first[a]; e != -1; e = next[e])
{
	// u[e]是起点，v[e]是终点，w[e]是权
}
