//������Сֵ 
int n, k;
int a[MAX_N], b[MAX_N];
int deq[MAX_N];   //˫�˶���

void solve(){
	int head = 0, tail = 0;  //˫�˶��е�ͷ����β��
	for (int i = 0; i < n; i++){  //��˫�˶��е�ĩβ���� i 
		while (head < tail && a[deq[tail-1]] >= a[i]) tail--;
		deq[tail++] = i;
		if (i - k + 1 >= 0) {
			b[i - k + 1] = a[deq[head]];
			if (deq[head] == i - k + 1) head++; //��˫�˶���ͷ��ɾ��Ԫ�� 
		}
	} 
}

 
