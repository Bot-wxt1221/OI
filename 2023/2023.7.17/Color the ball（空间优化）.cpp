//hdu 1556用差分数组求解
#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int D[N];               //a是气球，D是差分数组
int main() {
	int n;
	while(~scanf("%d",&n)) {		
		memset(D, 0, sizeof(D));
		for(int i = 1; i <= n; i++) {
			int L, R;
			scanf("%d%d", &L, &R);
			D[L]++;
			D[R+1]--;             //区间修改
		}
		for(int i = 1; i <= n; i++) {            //求原数组
			D[i] = D[i-1] + D[i];            //差分求前缀和，把已经使用过的较小的D[]拿来滚动，节约空间 
			if(i != n)  printf("%d ", D[i]);   //逐个打印结果
			else      printf("%d\n", D[i]);
		}          //小技巧：14行到17行，把a[]改成D[]也行
	}
	return 0;
}

/*
输入：
3
1 1
2 2
3 3
3
1 1
1 2
1 3
0

输出：
1 1 1
3 2 1
*/ 
