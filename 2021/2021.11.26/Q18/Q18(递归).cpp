/*
这个问题关键在于如何验证平方数。为验证相邻两数之和是否是平
方数，只要预先准备好平方数就相对简单了。因为相邻两块酥饼上的草
莓个数最多也不会超过 N 的 2 倍，所以可以事先计算好。
准确地说，相邻两个酥饼上的草莓个数之和最大应该是N+(N - 1)= 2N-1个。
切分后的酥饼是围成圆形的，首先固定最开始的一块酥饼，并假设
这块酥饼上的草莓个数为 1。因为其他切法都可以通过旋转酥饼得到，
所以这个假设的前提是成立的。
然后顺时针分配放置的草莓个数，保证每次放置的草莓个数都符合
条件，直到最后一块上的数字和最初的 1 相加也得到平方数。
*/ 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAX 105
using namespace std;
bool used[MAX];
int ans[MAX];
bool square[2 * MAX];
bool check(int n, int cur, int step);


int main(){
	//初始化 
	memset(used, false, sizeof(used));
	memset(square, false, sizeof(square));
	memset(ans, 0, sizeof(ans));
	//打表标记平方数（最大值为 n 的 2 倍）
	for(int i = 1; i <= floor(sqrt(2 * MAX)); i++){
		square[i * i] = true;		
	}		
	//从小到大枚举 
	int n = 2;	
	while(true){
		used[1] = true; 
		if(check(n, 1, 1))	break; //找到 1 种解法就结束	 	
		n += 1;			
	} 
	
	cout << n << endl;
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";	
	
	return 0;
}

bool check(int n, int cur, int step){
	ans[step] = cur;
	if(step == n){ //全部放置结束
		if(square[1 + cur]){  //1 和最后一个数之和为平方数时
			ans[step] = cur;
			return true; 
		}
	}	
	for(int i = 1; i <= n; i++){
		//遍历没有被使用的数字
		if(!used[i]){		
			if(square[i + cur]){ //如果和前一个数之和为平方数
				used[i] = true;				
				if(check(n, i, step + 1)) return true;	
				used[i] = false;				
			}				
		}
	}
	ans[step] = 0;
	return false;	                          
}
