int n, k;
int a[MAX_N], b[MAX_N];
deque<int> Q; // �洢���Ǳ��(�����±�)

for (int i = 0; i < n; ++i)	{
    if (!Q.empty() && i - Q.front() >= k)  Q.pop_front();  //�������ڳ��� k 
    while (!Q.empty() && a[Q.back()] > a[i]) // ���������ֵ������ĳ� < ����
        Q.pop_back();
    Q.push_back(i); // ���
    if (i >= k - 1)   b[i - k + 1] = a[Q.front()] ;
}
	
	
