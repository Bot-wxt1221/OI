int first[N]; // first[u]��ʾ��u�����ĵ�һ�� �ߵ����
int u[M],v[M],w[M], next[M]; // next[e]��ʾ���Ϊe����һ�� �ߵ����

memset(first, -1, sizeof(first));
for (int e = 0; e < m; e++)
{
	cin >> u[e] >> v[e] >> w[e];
	next[e] = first[u[e]];  // ����һ����
	first[u[e]] = e;
}

//�������� a ���������бߣ���ô����
for (int e = first[a]; e != -1; e = next[e])
{
	// u[e]����㣬v[e]���յ㣬w[e]��Ȩ
}
