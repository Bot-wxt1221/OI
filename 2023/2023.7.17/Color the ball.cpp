//hdu 1556用差分数组求解
#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N],D[N];               //a是气球，D是差分数组
int main() {
	int n;
	while(~scanf("%d",&n)) {
		memset(a,0,sizeof(a));
		memset(D,0,sizeof(D));
		for(int i=1; i<=n; i++) {
			int L,R;
			scanf("%d%d",&L,&R);
			D[L]++;
			D[R+1]--;             //区间修改
		}
		for(int i=1; i<=n; i++) {            //求原数组
			a[i] = a[i-1] + D[i];            //差分。求前缀和a[]，a[i]就是气球i的值
			if(i!=n)  printf("%d ", a[i]);   //逐个打印结果
			else      printf("%d\n",a[i]);
		}          //小技巧：14行到17行，把a[]改成D[]也行
	}
	return 0;
}

