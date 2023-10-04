#include<bits/stdc++.h>
using namespace std;
const int N = 500010;  // 自己定义一个范围
int olda[N];           // 离散化前
int newa[N];           // 离散化后
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&olda[i]);      //读元素的值
		newa[i] = olda[i];
	}
	sort(olda+1,olda+1+n);         //排序
	int cnt = n;
	//cnt = unique(olda+1,olda+1+n)-(olda+1);  //去重，cnt是去重后的数量
	for(int i=1; i<=cnt; i++)                //生成 newa[]
		newa[i]=lower_bound(olda+1,olda+1+n,newa[i])-olda;
	//查找相等的元素的位置，这个位置就是离散化后的新值
	for(int i=1; i<=cnt; i++)   printf("%d ",newa[i]); //打印出来看看
	printf("\n cnt=%d",cnt);
	return 0;
}

