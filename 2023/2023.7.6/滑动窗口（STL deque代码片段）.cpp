int n, k;
int a[MAX_N], b[MAX_N];
deque<int> Q; // 存储的是编号(数组下标)

for (int i = 0; i < n; ++i)	{
    if (!Q.empty() && i - Q.front() >= k)  Q.pop_front();  //超出窗口长度 k 
    while (!Q.empty() && a[Q.back()] > a[i]) // 求区间最大值把这里改成 < 即可
        Q.pop_back();
    Q.push_back(i); // 入队
    if (i >= k - 1)   b[i - k + 1] = a[Q.front()] ;
}
	
	
