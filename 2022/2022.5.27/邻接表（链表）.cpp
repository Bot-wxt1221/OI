struct edge
{
	int u, v, w;
	edge *next;
}mem[M]; // mem�൱�ڶ�̬�ڴ���䡣
int size = -1;

edge *adj[N]; // adj[i]������iΪ���ıߡ�

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
//�������� a ���������бߣ���ô����
for (edge *e=adj[a]; e!=NULL; e=e->next)
{
	// e->u����㣬e->v���յ㣬e->w��Ȩ
}
