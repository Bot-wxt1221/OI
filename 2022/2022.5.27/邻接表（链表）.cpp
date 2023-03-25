struct edge
{
	int u, v, w;
	edge *next;
}mem[M]; // mem相当于动态内存分配。
int size = -1;

edge *adj[N]; // adj[i]代表以i为起点的边。

memset(adj, 0, sizeof(adj));
for (int e = 0; e < m; e++)
{
	edge *p;
	p = &mem[++size]; 
	p -> next = NULL;
	cin >> (p -> u) >> (p -> v) >> (p -> w);
	p -> next = adj[p -> u];
	adj[p->u]=p;
}
//如果想检查从 a 出发的所有边，那么可以
for (edge *e=adj[a]; e!=NULL; e=e->next)
{
	// e->u是起点，e->v是终点，e->w是权
}
