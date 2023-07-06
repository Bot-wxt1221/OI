//滑动最小值 
int n, k;
int a[MAX_N], b[MAX_N];
int deq[MAX_N];   //双端队列

void solve(){
	int head = 0, tail = 0;  //双端队列的头部和尾部
	for (int i = 0; i < n; i++){  //在双端队列的末尾加入 i 
		while (head < tail && a[deq[tail-1]] >= a[i]) tail--;
		deq[tail++] = i;
		if (i - k + 1 >= 0) {
			b[i - k + 1] = a[deq[head]];
			if (deq[head] == i - k + 1) head++; //从双端队列头部删除元素 
		}
	} 
}

 
