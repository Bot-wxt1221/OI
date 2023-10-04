//离散化示例
#include<bits/stdc++.h>
const int N = 500010;   //自己定义一个范围
struct data {
	int val;              //元素的值
	int id;               //元素的位置
} olda[N];              //离散化之前的原始数据
int newa[N];            //离散化后的结果
bool cmp(data x,data y) {
	return x.val < y.val;    //用于sort()
}
int main() {
	int n;
	scanf("%d",&n);                  //读元素个数
	for(int i=1; i<=n; i++) {
		scanf("%d",&olda[i].val);                //读元素的值
		olda[i].id = i;                          //记录元素的位置
	}
	std::sort(olda+1,olda+1+n,cmp);              //对元素的值排序
	for(int i=1; i<=n; i++) {                    //生成 newa[]
		newa[olda[i].id]=i; //这个元素原来的位置在olda[i].id，把它的值赋为i，i是离散化后的新值
		if(olda[i].val == olda[i-1].val)          //若两个元素的原值相同，把新值赋为相同
			newa[olda[i].id] = newa[olda[i-1].id];
	}
	for(int i=1; i<=n; i++)  printf("%d ",newa[i]); //打印出来看看
	return 0;
}

