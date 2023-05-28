// �ݹ鷨����׺���ʽ��ֵ��O(n^2)
int calc(int l, int r) {
	// Ѱ��δ���κ����Ű��������һ���Ӽ���
	for (int i = r, j = 0; i >= l; i--) {
		if (s[i] == '(') j++;
		if (s[i] == ')') j--;
		if (j == 0 && s[i] == '+') return calc(l, i - 1) + calc(i + 1, r);
		if (j == 0 && s[i] == '-') return calc(l, i - 1) - calc(i + 1, r);
	}
	// Ѱ��δ���κ����Ű��������һ���˳���
	for (int i = r, j = 0; i >= l; i--) {
		if (s[i] == '(') j++;
		if (s[i] == ')') j--;
		if (j == 0 && s[i] == '*') return calc(l, i - 1) * calc(i + 1, r);
		if (j == 0 && s[i] == '/') return calc(l, i - 1) / calc(i + 1, r);
	}
	// ��β������
	if (s[l] == '('&&s[r] == ')') return calc(l + 1, r - 1);
	// ��һ����
	int ans = 0;
	for (int i = l; i <= r; i++) ans = ans * 10 + s[i] - '0';
	return ans;
}

// ----------------------------------------------------
// ��׺���ʽת��׺���ʽ��ͬʱ��ֵ��O(n)

// ��ֵջ 
vector<int> nums; 
// �����ջ 
vector<char> ops;

// ���ȼ� 
int grade(char op) {
	switch (op) {
	case '(':
		return 1;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	}
	return 0;
}

// �����׺���ʽ�е�һ������� 
void calc(char op) {
	// ��ջ��ȡ�������� 
	int y = *nums.rbegin();
	nums.pop_back();
	int x = *nums.rbegin();
	nums.pop_back();
	int z;
	switch (op) {
	case '+':
		z = x + y;
		break;
	case '-':
		z = x - y;
		break;
	case '*':
		z = x * y;
		break;
	case '/':
		z = x / y;
		break;
	}
	// ���������Ż�ջ�� 
	nums.push_back(z);	
}

// ��׺���ʽת��׺���ʽ��ͬʱ�Ժ�׺���ʽ��ֵ 
int solve(string s) {
	nums.clear();
	ops.clear();
	int top = 0, val = 0;
	for (int i = 0; i < s.size(); i++) {
		// ��׺���ʽ��һ������ 
		if (s[i] >= '0' && s[i] <= '9') {
			val = val * 10 + s[i] - '0';
			if (s[i+1] >= '0' && s[i+1] <= '9') continue;
			// ��׺���ʽ��һ������ֱ����ջ 
			nums.push_back(val);
			val = 0;
		}
		// ��׺���ʽ�������� 
		else if (s[i] == '(') ops.push_back(s[i]);
		// ��׺���ʽ�������� 
		else if (s[i] == ')') {
			while (*ops.rbegin() != '(') {
				// �����׺���ʽ��һ������� 
				calc(*ops.rbegin());
				ops.pop_back();
			}
			ops.pop_back();
		}
		// ��׺���ʽ�ļӼ��˳��� 
		else {
			while (ops.size() && grade(*ops.rbegin()) >= grade(s[i])) {
				calc(*ops.rbegin());
				ops.pop_back();
			}
			ops.push_back(s[i]);
		} 
	}
	while (ops.size()) {
		calc(*ops.rbegin());
		ops.pop_back();
	}
	// ��׺���ʽջ�����ʣ�µ������Ǵ� 
	return *nums.begin();
}

// ----------------------------------------------------
// ����ջ
a[n + 1] = p = 0;
for (int i = 1; i <= n + 1; i++) {
	if (a[i] > s[p]) {
		s[++p] = a[i], w[p] = 1;
	} else {
		int width=0;
		while (s[p] > a[i]) {
			width += w[p];
			ans = max(ans, (long long)width * s[p]);
			p--;
		}
		s[++p] = a[i], w[p] = width + 1;
	}
}
